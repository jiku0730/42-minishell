/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/27 14:54:45 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	prompt(void (*handler)(char *input, t_shell_table *shell_table),
		t_shell_table *shell_table)
{
	char	*input;

	while (1)
	{
		input = readline(PROMPT);
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
