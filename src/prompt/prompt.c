/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/01 16:49:19 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	prompt(int (*handler)(char *input))
{
	char	*input;
	int		should_continue;

	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input)
			add_history(input);
		should_continue = 1;
		if (handler)
			should_continue = handler(input);
		free(input);
		if (!should_continue)
			break ;
	}
	return (0);
}
