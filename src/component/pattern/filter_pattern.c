/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:40:49 by urassh            #+#    #+#             */
/*   Updated: 2025/12/01 03:22:08 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include <stdlib.h>

static bool	match_pattern(const char *str, const char *pattern);

t_list	*filter_pattern(t_list *source, const char *pattern)
{
	t_list	*result;
	t_list	*current;
	t_list	*new_node;

	if (!source || !pattern)
		return (NULL);
	result = NULL;
	current = source;
	while (current)
	{
		if (match_pattern((const char *)current->content, pattern))
		{
			new_node = ft_lstnew(ft_strdup((const char *)current->content));
			if (!new_node)
			{
				ft_lstclear(&result, free);
				return (NULL);
			}
			ft_lstadd_back(&result, new_node);
		}
		current = current->next;
	}
	return (result);
}

static bool	match_pattern(const char *str, const char *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');
	if (*pattern == WILDCARD)
	{
		while (*str)
		{
			if (match_pattern(str, pattern + 1))
				return (true);
			str++;
		}
		return (match_pattern(str, pattern + 1));
	}
	if (*str == *pattern)
		return (match_pattern(str + 1, pattern + 1));
	return (false);
}
