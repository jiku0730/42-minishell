/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/26 16:01:45 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_hash_table	*env;

	(void)argc;
	(void)argv;
	(void)envp;
	env = ht_create(128);
	if (!env)
		return (1);
	prompt(heredoc_checker, env);
	ht_destroy(env);
	return (0);
}
