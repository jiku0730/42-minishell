/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:18:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "signal_handler.h"

static int	fork_and_exec(t_ast *node, t_shell_table *shell_table)
{
	pid_t	pid;
	int		wstatus;
	char	**argv;

	pid = fork();
	if (pid < 0)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		if (node->cmd->redirs)
			if (exec_redirs(node->cmd->redirs) != 0)
				exit(1);
		argv = list_to_argv(node->cmd->argv);
		if (!argv || !argv[0])
			exit(127);
		exit(exec_external_cmd(argv, shell_table));
	}
	waitpid(pid, &wstatus, 0);
	if (ft_wifexited(wstatus))
		return (ft_wexitstatus(wstatus));
	return (1);
}

static void	restore_fds(int saved_in, int saved_out)
{
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
}

static int	exec_builtin_with_redir(t_ast *node, t_shell_table *st)
{
	int	saved_in;
	int	saved_out;
	int	status;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	if (node->cmd->redirs
		&& exec_redirs(node->cmd->redirs) != 0)
	{
		restore_fds(saved_in, saved_out);
		return (1);
	}
	status = exec_builtin_cmd(node, st);
	restore_fds(saved_in, saved_out);
	return (status);
}

int	exec_cmd(t_ast *node, t_shell_table *shell_table)
{
	int		status;

	status = exec_builtin_cmd(node, shell_table);
	if (status != -1)
	{
		if (node->cmd->redirs)
			return (exec_builtin_with_redir(node, shell_table));
		return (status);
	}
	return (fork_and_exec(node, shell_table));
}
