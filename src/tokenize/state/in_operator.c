/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 02:02:19 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_operator(t_token_store *store, t_token_state *state, char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (is_operator_char(current))
	{
		if (add_buffer(store, current) == ERROR)
			*state = ON_ERROR;
	}
	else
	{
		push_token(store);
		*state = IN_NORMAL;
		in_normal(store, state, current);
	}
}
