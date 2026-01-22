/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:17:37 by surayama          #+#    #+#             */
/*   Updated: 2026/01/22 22:17:58 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstswap(t_list *prev, t_list *target, t_list *new)
{
	t_list	*next_node;
	t_list	*last_new;

	if (!prev || !target || !new)
		return ;
	next_node = target->next;
	last_new = ft_lstlast(new);
	last_new->next = next_node;
	free(target->content);
	free(target);
	prev->next = new;
}
