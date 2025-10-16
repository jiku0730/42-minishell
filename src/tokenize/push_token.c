/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:13:34 by urassh            #+#    #+#             */
/*   Updated: 2025/10/16 23:16:11 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	push_token(t_list **list, char *token)
{
	t_list	*new_node;

	if (!list || !token)
		return (ERROR);
	new_node = ft_lstnew(token);
	if (!new_node)
	{
		free(token);
		return (ERROR);
	}
	ft_lstadd_back(list, new_node);
	return (SUCCESS);
}
