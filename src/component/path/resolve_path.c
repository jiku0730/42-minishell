/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                    :+:      :+:    :+:   */
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
static bool		has_path(const char *str);
static t_list	*handle_wildcard(t_list *prev, t_list *cur, t_list **head);
static void		handle_path(t_list *current);

t_list	*resolve_path(t_list *tokens)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = tokens;
	while (current)
	{
		if (has_wildcard((char *)current->content))
			prev = handle_wildcard(prev, current, &tokens);
		else if (has_path((char *)current->content))
		{
			handle_path(current);
			prev = current;
		}
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

static bool	has_path(const char *str)
{
	return (ft_strchr(str, '/') != NULL);
}

static t_list	*handle_wildcard(t_list *prev, t_list *cur, t_list **head)
{
	t_list	*resolved;

	resolved = resolve_wildcard((char *)cur->content);
	if (!resolved)
		return (cur);
	ft_lstreplace(prev, cur, resolved);
	if (!prev)
		*head = resolved;
	return (ft_lstlast(resolved));
}

static void	handle_path(t_list *current)
{
	char	*abs_path;

	abs_path = to_absolute_path((char *)current->content);
	if (abs_path)
	{
		free(current->content);
		current->content = abs_path;
	}
}
