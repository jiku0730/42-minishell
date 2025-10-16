/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 01:23:03 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_double_quote(t_token_store *store, t_token_state *state,
		char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_NORMAL;
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
}
