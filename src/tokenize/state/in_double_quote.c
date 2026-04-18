/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize_private.h"

void	in_double_quote(t_token_store *store, t_token_state *state,
		char current)
{
	if (current == '\0')
	{
		ft_putstr_fd("jikussh: unexpected EOF while looking"
			" for matching `\"'\n", STDERR_FILENO);
		*state = ON_ERROR;
	}
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_NORMAL;
}
