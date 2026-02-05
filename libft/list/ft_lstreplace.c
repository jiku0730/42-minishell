/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:36:30 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 16:26:58 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreplace(t_list *prev, t_list *target, t_list *new)
{
	t_list	*next_node;
	t_list	*last_new;

	if (!target || !new)
	{
		next_node = target->next;
		last_new = ft_lstlast(new);
		last_new->next = next_node;
		free(target->content);
		free(target);
	}
	if (prev)
		prev->next = new;
}
