/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_single_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 16:27:18 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "tokenize_internal.h"

void	in_single_quote(t_token_store *store, t_token_state *state,
		char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '\'')
		*state = IN_NORMAL;
}
