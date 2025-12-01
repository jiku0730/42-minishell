/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2025/12/01 13:57:16 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "path.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

void	path_checker(char *input, t_shell_table *shell_table)
{
	char	*absolute_path;

	(void)shell_table;
	if (ft_strncmp(input, "exit", 5) == 0)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		rl_clear_history();
		free(input);
		exit(0);
	}
	ft_putstr_fd("\n=== Path Checker ===\n", 1);
	ft_putstr_fd("Input: ", 1);
	ft_putendl_fd(input, 1);
	absolute_path = to_absolute(input);
	if (absolute_path)
	{
		ft_putstr_fd("Absolute Path: ", 1);
		ft_putendl_fd(absolute_path, 1);
		free(absolute_path);
	}
	else
	{
		ft_putstr_fd("Error: Failed to convert to absolute path\n", 1);
	}
	free(input);
}
