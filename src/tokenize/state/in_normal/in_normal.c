/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/17 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "tokenize_internal.h"
#include "in_normal_internal.h"

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
