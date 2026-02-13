/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/22 21:26:48 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

t_list	*append_path(t_list **dest, const char *content)
{
	char	*content_copy;

	if (!dest || !content)
		return (NULL);
	if (ft_strncmp(content, "..", 3) == 0)
	{
		if (*dest)
			ft_lstdel_back(dest, free);
		return (*dest);
	}
	else if (ft_strncmp(content, ".", 2) == 0)
		return (*dest);
	content_copy = ft_strdup(content);
	if (!content_copy)
	{
		ft_lstclear(dest, free);
		return (NULL);
	}
	ft_lstadd_back(dest, ft_lstnew(content_copy));
	return (*dest);
}
