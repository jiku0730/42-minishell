/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <sys/stat.h>

static int	cmd_path_error(char **argv)
{
	struct stat	sb;

	ft_putstr_fd("jikussh: ", STDERR_FILENO);
	if (stat(argv[0], &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
	}
	else
		perror(argv[0]);
	ft_free_array((void **)argv);
	return (126);
}

static int	cmd_not_found(char **argv)
{
	if (ft_strchr(argv[0], '/'))
	{
		if (access(argv[0], F_OK) == 0)
			return (cmd_path_error(argv));
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

int	exec_external_cmd(char **argv, t_shell_table *shell_table)
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
