/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 21:54:47 by kjikuhar         ###   ########.fr       */
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
// /* ---- Add this to the end of source file ---- */
// #include <assert.h>
// #include <stdio.h> /* ← For debugging (optional) */
// #include <stdlib.h>
// #include <string.h>

// /* ====== Helpers ====== */
// static int		g_del_count = 0;

// static void	*dup_int_times2(void *p)
// {
// 	int	*src;
// 	int	*dst;

// 	src = (int *)p;
// 	dst = malloc(sizeof(int));
// 	if (!dst)
// 		return (NULL);
// 	*dst = (*src) * 2;
// 	return (dst);
// }

// static void	*dup_int_fail_on_2(void *p)
// {
// 	int	*src;

// 	src = (int *)p;
// 	if (*src == 2)
// 		return (NULL);          /* Intentionally fail */
// 	return (dup_int_times2(p)); /* Succeed otherwise */
// }

// static void	del_int(void *p)
// {
// 	printf("del_int called: %p\n", p);
// 	free(p);
// 	g_del_count++;
// }

// static t_list	*make_int_node(int v)
// {
// 	int	*p;

// 	p = malloc(sizeof(int));
// 	assert(p); /* Simplified for testing */
// 	*p = v;
// 	return (ft_lstnew(p));
// }

// static int	list_equals(t_list *a, t_list *b)
// {
// 	while (a && b)
// 	{
// 		if (*(int *)a->content != *(int *)b->content)
// 			return (0);
// 		a = a->next;
// 		b = b->next;
// 	}
// 	return (a == NULL && b == NULL);
// }

// /* ====== ft_lstnew ====== */
// static void	test_ft_lstnew_content(void)
// {
// 	char	*s;
// 	t_list	*n;

// 	s = "hello";
// 	n = ft_lstnew(s);
// 	assert(n && n->content == s && n->next == NULL);
// 	free(n);
// }

// static void	test_ft_lstnew_null(void)
// {
// 	t_list	*n;

// 	n = ft_lstnew(NULL);
// 	assert(n && n->content == NULL && n->next == NULL);
// 	free(n);
// }

// /* ====== ft_lstclear ====== */
// static void	test_ft_lstclear_multi(void)
// {
// 	t_list	*a;

// 	g_del_count = 0;
// 	a = make_int_node(1);
// 	a->next = make_int_node(2);
// 	a->next->next = make_int_node(3);
// 	ft_lstclear(&a, del_int);
// 	assert(a == NULL);
// 	assert(g_del_count == 3);
// }

// static void	test_ft_lstclear_nullptr(void)
// {
// 	t_list	*head;

// 	/* lst == NULL */
// 	ft_lstclear(NULL, del_int);
// 	/* *lst == NULL */
// 	head = NULL;
// 	ft_lstclear(&head, del_int);
// }

// /* ====== ft_lstmap ====== */
// static void	test_ft_lstmap_success(void)
// {
// 	t_list	*src;
// 	t_list	*dst;

// 	src = make_int_node(1);
// 	src->next = make_int_node(2);
// 	src->next->next = make_int_node(3);
// 	dst = ft_lstmap(src, dup_int_times2, del_int);
// 	assert(dst && list_equals(dst, ((t_list[]){{.content = &(int){2},
// 				.next = &(t_list){.content = &(int){4},
// 				.next = &(t_list){.content = &(int){6}, .next = NULL}}}})));
// 	/* Original list is unchanged */
// 	assert(*(int *)src->content == 1);
// 	ft_lstclear(&src, del_int);
// 	ft_lstclear(&dst, del_int);
// }

// static void	test_ft_lstmap_fail_midway(void)
// {
// 	t_list	*src;
// 	t_list	*dst;

// 	g_del_count = 0;
// 	src = make_int_node(1);
// 	src->next = make_int_node(2);
// 	src->next->next = make_int_node(3);
// 	dst = ft_lstmap(src, dup_int_fail_on_2, del_int);
// 	assert(dst == NULL);
// 	assert(g_del_count == 1);   /* Only node 1 should have been freed */
// 	ft_lstclear(&src, del_int); /* Cleanup */
// }

// static void	test_ft_lstmap_nullsrc(void)
// {
// 	t_list	*dst;

// 	dst = ft_lstmap(NULL, dup_int_times2, del_int);
// 	assert(dst == NULL);
// }

// /* ====== main ====== */
// int	main(void)
// {
// 	/* ft_lstnew */
// 	test_ft_lstnew_content();
// 	test_ft_lstnew_null();
// 	/* ft_lstclear */
// 	test_ft_lstclear_multi();
// 	test_ft_lstclear_nullptr();
// 	/* ft_lstmap */
// 	test_ft_lstmap_success();
// 	test_ft_lstmap_fail_midway();
// 	printf("Final g_del_count = %d\n", g_del_count);
// 	test_ft_lstmap_nullsrc();
// 	puts("All tests passed!");
// 	return (0);
// }
