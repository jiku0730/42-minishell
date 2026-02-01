/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:12:08 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:55:53 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

static char	*build_token_from_buffer(t_list *buffer)
{
	int		size;
	char	*token;
	int		i;
	t_list	*current;

	size = ft_lstsize(buffer);
	if (size == 0)
		return (NULL);
	token = (char *)malloc(sizeof(char) * (size + 1));
	if (!token)
		return (NULL);
	i = 0;
	current = buffer;
	while (current)
	{
		token[i] = *(char *)(current->content);
		i++;
		current = current->next;
	}
	token[i] = '\0';
	return (token);
}

static bool	is_buffer_empty(const t_list *buffer)
{
	return (!buffer);
}

static t_list *new_expanded_node(char *str, t_shell_table *shell_table)
{
	char *expanded_str;

	if (!str)
		return (NULL);
	if (str[0] == '$')
	{
		expanded_str = st_search(shell_table, str + 1);
		if (!expanded_str)
			expanded_str = ft_strdup("");
		return (ft_lstnew(expanded_str));
	}
	return (ft_lstnew(str));
}

int	expand_push_token(t_expand_store *store, t_shell_table *shell_table)
{
	char	*token;
	t_list	*new_node;

	if (!store)
		return (ERROR);
	if (is_buffer_empty(store->buffer))
		return (SUCCESS);
	token = build_token_from_buffer(store->buffer);
	new_node = new_expanded_node(token, shell_table);
	if (!new_node)
	{
		free(token);
		return (ERROR);
	}
	ft_lstadd_back(&(store->tokens), new_node);
	ft_lstclear(&(store->buffer), free);
	store->buffer = NULL;
	return (SUCCESS);
}
