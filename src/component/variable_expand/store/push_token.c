/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:12:08 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:14:55 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../variable_expand_internal.h"
#include "variable_expand.h"

static char	*build_token_from_buffer(t_list *buffer)
{
	int		size;
	char	*token;
	int		i;
	t_list	*current;

	size = ft_lstsize(buffer);
	if (size == 0)
		return (NULL);
	token = (char *)malloc(sizeof(char) * (size + 1));
	if (!token)
		return (NULL);
	i = 0;
	current = buffer;
	while (current)
	{
		token[i] = *(char *)(current->content);
		i++;
		current = current->next;
	}
	token[i] = '\0';
	return (token);
}

int	expand_push_token(t_expand_store *store, t_shell_table *shell_table)
{
	char	*token;
	t_list	*new_node;

	(void)shell_table;
	if (!store)
		return (ERROR);
	if (!store->buffer)
		return (SUCCESS);
	token = build_token_from_buffer(store->buffer);
	if (!token)
	{
		ft_lstclear(&(store->buffer), free);
		store->buffer = NULL;
		return (SUCCESS);
	}
	new_node = ft_lstnew((void *)token);
	if (!new_node)
	{
		free(token);
		return (ERROR);
	}
	ft_lstadd_back(&(store->tokens), new_node);
	ft_lstclear(&(store->buffer), free);
	store->buffer = NULL;
	return (SUCCESS);
}
