/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:55:17 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:23:05 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"

t_list *variable_expand(t_list *tokens, t_shell_table *shell_table)
{
	t_list	*prev_token;
	t_list	*current_token;
	t_list	*expanded_token;

	current_token = tokens;
	prev_token = NULL;
	while (current_token)
	{
		expanded_token = expand_token(current_token->content, shell_table);
		if (!expanded_token)
			return (NULL);
		ft_lstreplace(prev_token, current_token, expanded_token);
		if (!prev_token)
			tokens = expanded_token;
		prev_token = expanded_token;
		current_token = current_token->next;
	}
	return (tokens);
}

static void	initialize(t_expand_store *store, t_expand_state *state,
		char **current, char *token)
{
	store->tokens = NULL;
	store->buffer = NULL;
	*current = token;
	*state = IN_NORMAL;
}

char	*expand_token(char *token, t_shell_table *shell_table)
{
	t_expand_store	store;
	t_expand_state	state;
	char			*current;

	if (!token)
		return (NULL);
	initialize(&store, &state, &current, token);
	while (true)
	{
		if (state == IN_NORMAL)
			in_normal(shell_table, &store, &state, *current);
		else if (state == IN_DOUBLE_QUOTE)
			in_double_quote(shell_table, &store, &state, *current);
		else if (state == IN_SINGLE_QUOTE)
			in_single_quote(shell_table, &store, &state, *current);
		current++;
	}
}
