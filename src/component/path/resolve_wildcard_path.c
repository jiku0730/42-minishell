/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_wildcard_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 13:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "pattern.h"
#include <stdbool.h>

static bool		has_wildcard(const char *str);
static t_list	*handle_wildcard(t_list *prev, t_list *current, t_list **head);

t_list	*resolve_wildcard_path(t_list *tokens)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = tokens;
	while (current)
	{
		if (has_wildcard((char *)current->content))
			prev = handle_wildcard(prev, current, &tokens);
		else
			prev = current;
		current = prev->next;
	}
	return (tokens);
}

static bool	has_wildcard(const char *str)
{
	return (ft_strchr(str, WILDCARD) != NULL);
}

static t_list	*handle_wildcard(t_list *prev, t_list *current, t_list **head)
{
	t_list	*resolved;

	resolved = resolve_wildcard((char *)current->content);
	if (!resolved)
		return (current);
	ft_lstreplace(prev, current, resolved);
	if (!prev)
		*head = resolved;
	return (ft_lstlast(resolved));
}
