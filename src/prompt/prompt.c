/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "signal.h"

void	prompt(void (*handler)(char *input, t_shell_table *shell_table),
		t_shell_table *shell_table)
{
	char	*input;

	while (1)
	{
		g_signal = 0;
		input = readline(PROMPT);
		if (!input && g_signal == SIGINT)
			continue ;
		if (!input)
			break ;
		if (is_blank_line(input))
		{
			free(input);
			continue ;
		}
		if (*input)
			add_history(input);
		if (handler)
			handler(input, shell_table);
	}
	rl_clear_history();
}
