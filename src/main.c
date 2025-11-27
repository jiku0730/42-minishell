/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 14:54:45 by urassh           ###   ########.fr       */
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
	prompt(parser_checker, shell_table);
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
