/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/23 00:31:24 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void by_operator(t_token_store *store, t_token_state *state,
		const char current);
static void by_normal(t_token_store *store, t_token_state *state,
		const char current);

void	in_operator(t_token_store *store, t_token_state *state,
		const char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (is_operator_char(current))
		by_operator(store, state, current);
	else
		by_normal(store, state, current);
}

static void	by_operator(t_token_store *store, t_token_state *state,
		const char current)
{
	if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
		*state = IN_NORMAL;
}

static void	by_normal(t_token_store *store, t_token_state *state,
		const char current)
{
	if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
	{
		*state = IN_NORMAL;
		in_normal(store, state, current);
	}
}
