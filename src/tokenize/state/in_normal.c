/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize_private.h"

void	by_last(t_token_store *store, t_token_state *state, char current);
void	by_space(t_token_store *store, t_token_state *state, char current);
void	by_quote(t_token_store *store, t_token_state *state, char current);
void	by_operator(t_token_store *store, t_token_state *state, char current);
void	by_parenthesis(t_token_store *store, t_token_state *state,
			char current);

void	in_normal(t_token_store *store, t_token_state *state, char current)
{
	if (current == '\0')
		by_last(store, state, current);
	else if (ft_isspace(current))
		by_space(store, state, current);
	else if (is_parenthesis(current))
		by_parenthesis(store, state, current);
	else if (is_operator_char(current))
		by_operator(store, state, current);
	else if (is_quote(current))
		by_quote(store, state, current);
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
}
