/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:13:34 by urassh            #+#    #+#             */
/*   Updated: 2025/10/12 22:42:27 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	push_token(t_list **list, char *token)
{
	t_list	*new_node;

	if (!list || !token)
		return ;
	new_node = ft_lstnew(token);
	if (!new_node)
	{
		free(token);
		return ;
	}
	ft_lstadd_back(list, new_node);
}
