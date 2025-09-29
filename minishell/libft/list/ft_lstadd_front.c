/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:47:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 18:52:16 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the given node to the beginning of the list. Works with empty lists. */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include <string.h>

// t_list	*listMake(char *content)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = (char *)malloc(sizeof(char) * (strlen(content)));
// 	strcpy((char *)(new->content), (const char *)content);
// 	new->next = NULL;
// 	return (new);
// }

// int	main(void)
// {
// 	t_list	*lst1, *lst2, *lst3;
// 	t_list *head;

// 	lst1 = listMake("Hello World!1");
// 	lst2 = listMake("Hello World!2");
// 	lst3 = listMake("Hello World!3");

// 	head = lst1;
// 	lst1->next = lst2;
// 	lst2->next = NULL;
// 	lst3->next = NULL;

// 	printf("%s\n", (char *)(lst1->content));
// 	printf("%s\n", (char *)(lst2->content));
// 	printf("%s\n", (char *)(lst3->content));

// 	t_list *current = head;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (!current)
// 		{
// 			printf("%p\n", current);
// 			break ;
// 		}
// 		printf("%s\n", (char *)(current->content));
// 		current = current->next;
// 	}
// 	printf("\n");

// 	head = NULL;
// 	ft_lstadd_front(&head, lst3);
// 	current = head;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (!current)
// 		{
// 			printf("%p\n", current);
// 			break ;
// 		}
// 		printf("%s\n", (char *)(current->content));
// 		current = current->next;
// 	}
// 	return (0);
// }
