/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:57:58 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*init_head(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*tmp;
	t_list	*head;

	tmp = (*f)(lst->content);
	if (!tmp)
		return (NULL);
	head = ft_lstnew(tmp);
	if (!head)
		return (del(tmp), NULL);
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;
	t_list	*tmp_node;
	void	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = init_head(lst, f, del);
	if (!head)
		return (NULL);
	cur = head;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst->content);
		if (!tmp)
			return (ft_lstclear(&head, del), NULL);
		tmp_node = ft_lstnew(tmp);
		if (!tmp_node)
			return (del(tmp), ft_lstclear(&head, del), NULL);
		cur->next = tmp_node;
		cur = tmp_node;
		lst = lst->next;
	}
	return (head);
}
