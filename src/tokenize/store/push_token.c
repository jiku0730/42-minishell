/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:13:34 by surayama          #+#    #+#             */
/*   Updated: 2026/01/17 02:33:02 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

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

static char	*consume_operator_token(char **token_ptr)
{
	char	*initial_token;
	char	*operator_token;
	char	*remained_token;
	size_t	operator_token_length;

	initial_token = *token_ptr;
	operator_token_length = operator_length(initial_token);
	operator_token = ft_substr(initial_token, 0, operator_token_length);
	remained_token = NULL;
	if (!operator_token)
		return (NULL);
	if (operator_token_length != ft_strlen(initial_token))
	{
		remained_token = ft_strdup(initial_token + operator_token_length);
		if (!remained_token)
		{
			free(operator_token);
			operator_token = NULL;
		}
	}
	free(initial_token);
	*token_ptr = remained_token;
	return (operator_token);
}

static int	add_back_token(char *token, t_token_store *store)
{
	t_list	*new_node;

	new_node = ft_lstnew(token);
	if (!new_node)
	{
		free(token);
		return (ERROR);
	}
	ft_lstadd_back(&(store->tokens), new_node);
	return (SUCCESS);
}

static int	push_operator_tokens(t_token_store *store, char *token)
{
	char	*operator_token;
	int		result;

	while (token)
	{
		operator_token = consume_operator_token(&token);
		if (!operator_token)
		{
			free(token);
			return (ERROR);
		}
		result = add_back_token(operator_token, store);
		if (result == ERROR)
		{
			free(token);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	push_token(t_token_store *store)
{
	char	*token;
	int		result;

	if (!store)
		return (ERROR);
	if (!store->buffer)
		return (SUCCESS);
	token = build_token_from_buffer(store->buffer);
	if (!token)
		return (ERROR);
	if (is_operator(token))
		result = push_operator_tokens(store, token);
	else
		result = add_back_token(token, store);
	ft_lstclear(&(store->buffer), free);
	store->buffer = NULL;
	return (result);
}
