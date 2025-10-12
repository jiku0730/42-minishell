/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/13 00:30:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	in_operator(t_list **token_list, char **begin_ptr, char **current_ptr,
		t_token_state *state)
{
	size_t	len;
	char	*token;
	size_t	operator_len;

	if (*begin_ptr < *current_ptr)
	{
		len = *current_ptr - *begin_ptr;
		token = ft_substr(*begin_ptr, 0, len);
		push_token(token_list, token);
	}
	if (ft_strncmp(*current_ptr, "&&", 2) == 0 || ft_strncmp(*current_ptr,
			"||", 2) == 0 || ft_strncmp(*current_ptr, "<<", 2) == 0
		|| ft_strncmp(*current_ptr, ">>", 2) == 0)
		operator_len = 2;
	else
		operator_len = 1;
	token = ft_substr(*current_ptr, 0, operator_len);
	push_token(token_list, token);
	*current_ptr += operator_len - 1;
	*begin_ptr = *current_ptr + 1;
	*state = IN_NORMAL;
}
