/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_single_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/16 23:03:19 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_single_quote(t_list **token_list, char **begin_ptr,
		char **current_ptr, t_token_state *state)
{
	size_t	len;
	char	*token;

	if (!**current_ptr)
		*state = ON_ERROR;
	else if (ft_strncmp(*current_ptr, "'", 1) == 0)
	{
		len = *current_ptr - *begin_ptr;
		token = ft_substr(*begin_ptr, 0, len);
		if (!token)
			*state = ON_ERROR;
		else
		{
			push_token(token_list, token);
			*begin_ptr = *current_ptr + 1;
			*state = IN_NORMAL;
		}
	}
}
