/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/02/13 23:37:48 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main_prod(int argc, char const **argv, char *const envp[])
{
	t_shell_table	*shell_table;

	(void)argc;
	(void)argv;
	shell_table = build_shell_table(envp);
	if (!shell_table)
		return (1);
	prompt(on_input, shell_table);
	st_destroy(shell_table);
	return (0);
}

int	main_dev(int argc, char const **argv, char *const envp[])
{
	t_shell_table	*shell_table;

	(void)argc;
	(void)argv;
	shell_table = build_shell_table(envp);
	if (!shell_table)
		return (1);
	shell_table_checker(shell_table);
	prompt(expand_checker, shell_table);
	st_destroy(shell_table);
	return (0);
}

int	main(int argc, char const **argv, char *const envp[])
{
	if (argc > 1 && ft_strncmp(argv[1], "--dev", 6) == 0)
		return (main_dev(argc, argv, envp));
	else
		return (main_prod(argc, argv, envp));
}
