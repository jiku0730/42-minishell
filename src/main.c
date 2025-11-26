/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/26 17:27:11 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main_prod(int argc, char **argv, char **envp)
{
	t_hash_table	*env_table;

	(void)argc;
	(void)argv;
	env_table = build_env_table(envp);
	if (!env_table)
		return (1);
	prompt(on_input, env_table);
	ht_destroy(env_table);
	return (0);
}

int	main_dev(int argc, char **argv, char **envp)
{
	t_hash_table	*env_table;

	(void)argc;
	(void)argv;
	env_table = build_env_table(envp);
	if (!env_table)
		return (1);
	env_table_checker(env_table);
	prompt(heredoc_checker, env_table);
	ht_destroy(env_table);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && ft_strncmp(argv[1], "--dev", 6) == 0)
		return (main_dev(argc, argv, envp));
	else
		return (main_prod(argc, argv, envp));
}
