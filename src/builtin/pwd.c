/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:16:00 by surayama          #+#    #+#             */
/*   Updated: 2025/11/29 20:29:40 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

int	pwd(t_list *argv, t_shell_table *shell_table)
{
	char	*pwd_path;

	(void)argv;
	pwd_path = st_search(shell_table, "PWD");
	if (pwd_path)
	{
		printf("%s\n", pwd_path);
		return (SUCCESS);
	}
	pwd_path = getcwd(NULL, 0);
	if (!pwd_path)
	{
		perror("pwd");
		return (ERROR);
	}
	printf("%s\n", pwd_path);
	free(pwd_path);
	return (SUCCESS);
}
