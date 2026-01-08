/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_single_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/12/06 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_single_quote(t_token_store *store, t_token_state *state,
		const char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '\'')
		*state = IN_NORMAL;
}
