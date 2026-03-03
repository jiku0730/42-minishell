/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:08:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/03/03 13:49:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_cmd_core(char **argv, t_shell_table *shell_table)
{
	char		*cmd_path;
	char		**new_envp;

	cmd_path = find_command(argv[0], shell_table);
	if (!cmd_path)
	{
		ft_free_array(argv);
		return (126);
	}
	new_envp = export_envp(shell_table);
	if (!new_envp)
	{
		free(cmd_path);
		ft_free_array(argv);
		return (1);
	}
	execve(cmd_path, argv, new_envp);
	perror(cmd_path);
	free(cmd_path);
	st_destroy(shell_table);
	ft_free_array(new_envp);
	ft_free_array(argv);
	return (127);
}
