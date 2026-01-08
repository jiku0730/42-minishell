/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:08:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:38:17 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_cmd_core(char **argv, t_shell_table *shell_table)
{
	char	*cmd_path;

	cmd_path = find_command(argv[0], shell_table);
	if (!cmd_path)
	{
		ft_free_split(argv);
		return (126);
	}
	execve(cmd_path, argv, shell_table);
	perror(cmd_path);
	free(cmd_path);
	ft_free_split(argv);
	return (127);
}
