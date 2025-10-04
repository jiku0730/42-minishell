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

void	prompt(void (*handler)(char *input))
{
	char	*input;

	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input)
			add_history(input);
		if (handler)
			handler(input);
	}
}
