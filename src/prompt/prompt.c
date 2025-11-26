/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/26 16:01:54 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	prompt(void (*handler)(char *input, t_hash_table *env),
		t_hash_table *env)
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
			handler(input, env);
	}
	rl_clear_history();
}
