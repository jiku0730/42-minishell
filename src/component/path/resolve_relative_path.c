/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_relative_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 13:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include <stdbool.h>

static bool	has_path(const char *str);

t_list	*resolve_relative_path(t_list *tokens)
{
	t_list	*current;
	char	*abs_path;

	current = tokens;
	while (current)
	{
		if (has_path((char *)current->content))
		{
			abs_path = to_absolute_path((char *)current->content);
			if (abs_path)
			{
				free(current->content);
				current->content = abs_path;
			}
		}
		current = current->next;
	}
	return (tokens);
}

static bool	has_path(const char *str)
{
	return (ft_strchr(str, '/') != NULL);
}
