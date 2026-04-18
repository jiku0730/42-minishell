/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char *const envp[])
{
	t_shell_table	*shell_table;
	int				last_status;

	(void)argc;
	(void)argv;
	shell_table = build_shell_table(envp);
	if (!shell_table)
		return (1);
	setup_signal_handlers();
	last_status = prompt(on_input, shell_table);
	st_destroy(shell_table);
	return (last_status);
}
