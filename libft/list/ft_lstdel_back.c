/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/12/01 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_back(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*last;

	if (!lst || !*lst || !del)
		return ;
	if (!(*lst)->next)
	{
		ft_lstdelone(*lst, del);
		*lst = NULL;
		return ;
	}
	last = ft_lstlast(*lst);
	current = *lst;
	while (current->next != last)
		current = current->next;
	current->next = NULL;
	ft_lstdelone(last, del);
}
