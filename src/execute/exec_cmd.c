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
#include "expand.h"

static int	cmd_not_found(char **argv)
{
	if (ft_strchr(argv[0], '/'))
	{
		if (access(argv[0], F_OK) == 0)
		{
			ft_putstr_fd("jikussh: ", STDERR_FILENO);
			perror(argv[0]);
			ft_free_array((void **)argv);
			return (126);
		}
		ft_putstr_fd("jikussh: ", STDERR_FILENO);
		perror(argv[0]);
		ft_free_array((void **)argv);
		return (127);
	}
	ft_putstr_fd("jikussh: ", STDERR_FILENO);
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	ft_free_array((void **)argv);
	return (127);
}

static int	exec_external_cmd(char **argv, t_shell_table *shell_table)
{
	char		*cmd_path;
	char		**new_envp;

	cmd_path = find_exec_path(argv[0], shell_table);
	if (!cmd_path)
		return (cmd_not_found(argv));
	new_envp = export_envp(shell_table);
	if (!new_envp)
	{
		free(cmd_path);
		ft_free_array((void **)argv);
		return (1);
	}
	execve(cmd_path, argv, new_envp);
	perror(cmd_path);
	free(cmd_path);
	st_destroy(shell_table);
	ft_free_array((void **)new_envp);
	ft_free_array((void **)argv);
	return (127);
}

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

int	exec_cmd(t_ast *node, t_shell_table *shell_table)
{
	int		status;

	node->cmd->argv = expand(node->cmd->argv, shell_table);
	if (node->cmd->redirs)
		expand_redir_filenames(node->cmd->redirs, shell_table);
	if (node->cmd->redirs)
	{
		if (exec_redirs(node->cmd->redirs) != 0)
			return (1);
	}
	status = exec_builtin_cmd(node, shell_table);
	if (status != -1)
		return (status);
	return (fork_and_exec(node, shell_table));
}
