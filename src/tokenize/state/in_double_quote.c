/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_double_quote(t_token_store *store, t_token_state *state,
		char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_NORMAL;
}
