/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 18:36:50 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function frees the memory of a list node using the given function */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->content)
		(*del)(lst->content);
	free(lst);
}

// #include <stdio.h>
// #include <string.h>

// void	delete_content(void *content)
// {
// 	free(content);

// }

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
// 	printf("\n");

// 	t_list *current = head;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		if (!current)
// 		{
// 			printf("%p\n", current);
// 			break ;
// 		}
// 		printf("%s\n", (char *)(current->content));
// 		current = current->next;
// 	}

// 	ft_lstdelone(lst2, *delete_content);
// 	current = head;
// 	for (int i = 0; i < 5; i++)
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
