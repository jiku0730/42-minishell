/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:16:00 by surayama          #+#    #+#             */
/*   Updated: 2025/12/01 15:13:22 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

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
