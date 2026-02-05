/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:55:17 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:53:58 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

static t_list	*expand_token(char *token, t_shell_table *shell_table);

t_list *variable_expand(t_list *tokens, t_shell_table *shell_table)
{
	t_list	*prev_token;
	t_list	*current_token;
	t_list	*next_token;
	t_list	*expanded_token;

	current_token = tokens;
	prev_token = NULL;
	while (current_token)
	{
		next_token = current_token->next;
		expanded_token = expand_token(current_token->content, shell_table);
		if (!expanded_token)
			return (NULL);
		ft_lstreplace(prev_token, current_token, expanded_token);
		if (!prev_token)
			tokens = expanded_token;
		prev_token = expanded_token;
		current_token = next_token;
	}
	return (tokens);
}

static void	initialize(t_expand_store *store, t_expand_state *state,
		char **current, char *token)
{
	store->tokens = NULL;
	store->buffer = NULL;
	store->skip_count = 0;
	*current = token;
	*state = EXPAND_IN_NORMAL;
}

static t_list	*expand_token(char *token, t_shell_table *shell_table)
{
	t_expand_store	store;
	t_expand_state	state;
	char			*current;

	if (!token)
		return (NULL);
	initialize(&store, &state, &current, token);
	while (true)
	{
		if (state == EXPAND_IN_NORMAL)
			expand_in_normal(shell_table, &store, &state, &current);
		else if (state == EXPAND_IN_DOUBLE_QUOTE)
			expand_in_double_quote(shell_table, &store, &state, &current);
		else if (state == EXPAND_IN_SINGLE_QUOTE)
			expand_in_single_quote(shell_table, &store, &state, &current);
		else if (state == EXPAND_ON_SUCCESS)
			return (expand_on_success(&store, token));
		else if (state == EXPAND_ON_ERROR)
			return (expand_on_error(&store, token));
		current++;
		if (store.skip_count > 0)
		{
			current += store.skip_count;
			store.skip_count = 0;
		}
	}
}
