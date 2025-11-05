/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:54:52 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 14:02:03 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_quote(t_token_store *store, t_token_state *state, const char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (is_quote_char(current))
		*state = IN_NORMAL;
}
