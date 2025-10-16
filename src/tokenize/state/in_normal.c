/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 02:00:23 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	by_last(t_token_store *store, t_token_state *state, char current);
static void	by_space(t_token_store *store, t_token_state *state, char current);
static void	by_quote(t_token_store *store, t_token_state *state, char current);
static void	by_operator(t_token_store *store, t_token_state *state,
				char current);

void	in_normal(t_token_store *store, t_token_state *state, char current)
{
	if (current == '\0')
		by_last(store, state, current);
	else if (ft_isspace(current))
		by_space(store, state, current);
	else if (is_operator_char(current))
		by_operator(store, state, current);
	else if (current == '\"' || current == '\'')
		by_quote(store, state, current);
	else
		add_buffer(store, current);
}

static void	by_last(t_token_store *store, t_token_state *state, char current)
{
	(void)current;
	if (!store->buffer || push_token(store) == ERROR)
	{
		*state = ON_ERROR;
		return ;
	}
	*state = ON_SUCCESS;
}

static void	by_space(t_token_store *store, t_token_state *state, char current)
{
	(void)current;
	if (!store->buffer || push_token(store) == ERROR)
	{
		*state = ON_ERROR;
		return ;
	}
	*state = IN_NORMAL;
}

static void	by_quote(t_token_store *store, t_token_state *state, char current)
{
	if (!store->buffer)
	{
		*state = ON_ERROR;
		return ;
	}
	if (current == '\"')
		*state = IN_DOUBLE_QUOTE;
	else if (current == '\'')
		*state = IN_SINGLE_QUOTE;
}

static void	by_operator(t_token_store *store, t_token_state *state,
		char current)
{
	if (!store->buffer || push_token(store) == ERROR || add_buffer(store,
			current) == ERROR)
	{
		*state = ON_ERROR;
		return ;
	}
	*state = IN_OPERATOR;
}
