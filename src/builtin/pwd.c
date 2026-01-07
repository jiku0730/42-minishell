/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:16:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/07 21:11:50 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	pwd(t_list *argv, t_shell_table *shell_table)
{
	char	*pwd_path;

	(void)argv;
	(void)shell_table;
	pwd_path = getcwd(NULL, 0);
	if (!pwd_path)
	{
		perror("pwd");
		return (EXIT_FAILURE);
	}
	printf("%s\n", pwd_path);
	free(pwd_path);
	return (EXIT_SUCCESS);
}
