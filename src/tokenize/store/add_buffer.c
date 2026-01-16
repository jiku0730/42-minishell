/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 14:33:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	add_buffer(t_token_store *store, char c)
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
