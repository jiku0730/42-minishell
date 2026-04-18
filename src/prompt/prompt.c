/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/18 17:06:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "signal_handler.h"

static int	apply_sigint_status(int last_status)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		return (130);
	}
	return (last_status);
}

int	prompt(int (*handler)(char *input, t_shell_table *shell_table,
			int last_status), t_shell_table *shell_table)
{
	char	*input;
	int		last_status;

	last_status = 0;
	while (1)
	{
		input = readline(PROMPT);
		last_status = apply_sigint_status(last_status);
		if (!input)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		if (is_blank_line(input))
		{
			free(input);
			continue ;
		}
		if (*input)
			add_history(input);
		if (handler)
			last_status = handler(input, shell_table, last_status);
	}
	rl_clear_history();
	return (last_status);
}
