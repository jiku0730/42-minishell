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
#include <stdio.h>
#include <stdlib.h>

void	path_checker(char *input, t_shell_table *shell_table)
{
	char	*absolute_path;

	(void)shell_table;
	if (ft_strncmp(input, "exit", 5) == 0)
	{
		printf("exit\n");
		rl_clear_history();
		free(input);
		exit(0);
	}
	printf("\n=== Path Checker ===\n");
	printf("Input: %s\n", input);
	absolute_path = to_absolute(input);
	if (absolute_path)
	{
		printf("Absolute Path: %s\n", absolute_path);
		free(absolute_path);
	}
	else
	{
		ft_putendl_fd("Error: Failed to convert to absolute path", 2);
	}
	free(input);
}
