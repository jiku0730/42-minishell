/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 14:33:36 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	by_operator(t_token_store *store, t_token_state *state,
				char current);
static void	by_normal(t_token_store *store, t_token_state *state, char current);

void	in_operator(t_token_store *store, t_token_state *state, char current)
{
	if (current == '\0' && push_token(store))
		*state = ON_SUCCESS;
	else if (is_operator(current))
		by_operator(store, state, current);
	else
		by_normal(store, state, current);
}

static void	by_operator(t_token_store *store, t_token_state *state,
		char current)
{
	if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
		*state = IN_NORMAL;
}

static void	by_normal(t_token_store *store, t_token_state *state, char current)
{
	if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
	{
		*state = IN_NORMAL;
		in_normal(store, state, current);
	}
}
