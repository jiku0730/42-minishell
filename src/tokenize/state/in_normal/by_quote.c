/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_normal_internal.h"

void	by_quote(t_token_store *store, t_token_state *state, char current)
{
	if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_DOUBLE_QUOTE;
	else if (current == '\'')
		*state = IN_SINGLE_QUOTE;
}
