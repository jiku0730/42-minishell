/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:13:34 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

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

int	push_token(t_token_store **store)
{
	char	*token;
	t_list	*new_node;

	if (!store || !*store)
		return (ERROR);
	token = build_token_from_buffer((*store)->buffer);
	if (!token)
		return (ERROR);
	new_node = ft_lstnew(token);
	if (!new_node)
	{
		free(token);
		return (ERROR);
	}
	ft_lstadd_back(&((*store)->tokens), new_node);
	ft_lstclear(&((*store)->buffer), free);
	(*store)->buffer = NULL;
	return (SUCCESS);
}
