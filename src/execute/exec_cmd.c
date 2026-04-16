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
#include "path.h"

static char	*find_in_path(const char *cmd, t_shell_table *shell_table)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;

	path_env = st_search(shell_table, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (!full_path)
			return (ft_free_array((void **)paths), NULL);
		if (access(full_path, X_OK) == 0)
			return (ft_free_array((void **)paths), full_path);
		free(full_path);
		i++;
	}
	ft_free_array((void **)paths);
	return (NULL);
}

char	*find_exec_path(const char *cmd, t_shell_table *shell_table)
{
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (find_in_path(cmd, shell_table));
}

static int	exec_external_cmd(char **argv, t_shell_table *shell_table)
{
	char		*cmd_path;
	char		**new_envp;

	cmd_path = find_exec_path(argv[0], shell_table);
	if (!cmd_path)
	{
		ft_free_array((void **)argv);
		return (126);
	}
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
