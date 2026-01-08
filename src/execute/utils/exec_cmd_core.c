/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:08:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:29:53 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_cmd_core(char **argv, char *const envp[])
{
	char	*cmd_path;

	cmd_path = find_command(argv[0], shell_table);
	if (!cmd_path)
	{
		ft_free_split(argv);
		return (126);
	}
	execve(cmd_path, argv, envp);
	perror(cmd_path);
	free(cmd_path);
	ft_free_split(argv);
	return (127);
}
