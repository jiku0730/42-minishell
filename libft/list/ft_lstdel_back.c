/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
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
