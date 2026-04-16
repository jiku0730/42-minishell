/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_wildcard_internal.h"

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
				return (ft_lstclear(&result, free), NULL);
			ft_lstadd_back(&result, new_node);
		}
		current = current->next;
	}
	return (result);
}
