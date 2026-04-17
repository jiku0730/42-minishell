/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/17 21:22:08 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "signal_handler.h"

void	prompt(int (*handler)(char *input, t_shell_table *shell_table,
			int last_status), t_shell_table *shell_table)
{
	char	*input;
	int		last_status;

	last_status = 0;
	while (1)
	{
		input = readline(PROMPT);
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
}
