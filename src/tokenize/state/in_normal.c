/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 14:33:32 by kjikuhar         ###   ########.fr       */
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
	else if (is_operator(current))
		by_operator(store, state, current);
	else if (is_quote(current))
		by_quote(store, state, current);
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
}

static void	by_last(t_token_store *store, t_token_state *state, char current)
{
	(void)current;
	if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
		*state = ON_SUCCESS;
}

static void	by_space(t_token_store *store, t_token_state *state, char current)
{
	(void)current;
	if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
		*state = IN_NORMAL;
}

static void	by_operator(t_token_store *store, t_token_state *state,
		char current)
{
	if (push_token(store) == ERROR || add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else
		*state = IN_OPERATOR;
}

static void	by_quote(t_token_store *store, t_token_state *state, char current)
{
	if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_DOUBLE_QUOTE;
	else if (current == '\'')
		*state = IN_SINGLE_QUOTE;
}
