/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:41:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/03/03 13:49:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**list_to_argv(t_list *lst)
{
	size_t	count;
	size_t	i;
	char	**out;

	count = ft_lstsize(lst);
	out = malloc(sizeof(char *) * (count + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (lst)
	{
		out[i] = ft_strdup((const char *)lst->content);
		if (!out[i])
		{
			ft_free_array(out);
			return (NULL);
		}
		i++;
		lst = lst->next;
	}
	out[i] = NULL;
	return (out);
}
