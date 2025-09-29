/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:34:58 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 19:03:32 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in a list */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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
// 	lst2->next = lst3;
// 	lst3->next = NULL;

// 	printf("%s\n", (char *)(lst1->content));
// 	printf("%s\n", (char *)(lst2->content));
// 	printf("%s\n", (char *)(lst3->content));
// 	printf("\n");

// 	t_list *current = head;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		if (!current)
// 		{
// 			printf("%p : %d\n", current, ft_lstsize(current));
// 			break ;
// 		}
// 		printf("%s : %d\n", (char *)(current->content), ft_lstsize(current));
// 		current = current->next;
// 	}

// 	current = head;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		if (!current)
// 		{
// 			printf("%p : %d\n", current, ft_lstsize(current));
// 			break ;
// 		}
// 		printf("%s : %d\n", (char *)(current->content), ft_lstsize(current));
// 		current = current->next;
// 	}
// 	return (0);
// }
