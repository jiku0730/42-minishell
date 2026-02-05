/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:10:42 by surayama          #+#    #+#             */
/*   Updated: 2026/02/02 00:09:22 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

int	expand_add_buffer(t_expand_store *store, char c)
{
	char	*char_ptr;
	t_list	*new_node;

	if (!store)
		return (ERROR);
	char_ptr = (char *)malloc(sizeof(char));
	if (!char_ptr)
		return (ERROR);
	*char_ptr = c;
	new_node = ft_lstnew(char_ptr);
	if (!new_node)
	{
		free(char_ptr);
		return (ERROR);
	}
	ft_lstadd_back(&(store->buffer), new_node);
	return (SUCCESS);
}
