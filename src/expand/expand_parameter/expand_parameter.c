/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:55:17 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 17:58:51 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "expand_parameter_internal.h"

static t_list	*expand_token(char *token, t_shell_table *shell_table);
static t_list	*remove_current_token(t_list *tokens, t_list *prev_token,
					t_list *current_token, t_list *next_token);
static t_list	*insert_expanded_token(t_list **tokens, t_list *prev_token,
					t_list *current_token, t_list *expanded_token);

t_list	*expand_parameter(t_list *tokens, t_shell_table *shell_table)
{
	t_list	*prev_token;
	t_list	*current_token;
	t_list	*next_token;
	t_list	*expanded_token;

	current_token = tokens;
	prev_token = NULL;
	while (current_token && current_token->content)
	{
		next_token = current_token->next;
		expanded_token = expand_token(current_token->content, shell_table);
		if (expanded_token)
			prev_token = insert_expanded_token(&tokens, prev_token,
					current_token, expanded_token);
		else
			tokens = remove_current_token(tokens, prev_token, current_token,
					next_token);
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

	initialize(&store, &state, &current, token);
	while (true)
	{
		if (state == EXPAND_IN_NORMAL)
			in_normal_expand(shell_table, &store, &state, &current);
		else if (state == EXPAND_IN_DOUBLE_QUOTE)
			in_double_quote_expand(shell_table, &store, &state, &current);
		else if (state == EXPAND_IN_SINGLE_QUOTE)
			in_single_quote_expand(shell_table, &store, &state, &current);
		else if (state == EXPAND_ON_SUCCESS)
			return (on_success_expand(&store, token));
		else if (state == EXPAND_ON_ERROR)
			return (on_error_expand(&store, token));
		current++;
		if (store.skip_count > 0)
		{
			current += store.skip_count;
			store.skip_count = 0;
		}
	}
}

static t_list	*insert_expanded_token(t_list **tokens, t_list *prev_token,
		t_list *current_token, t_list *expanded_token)
{
	t_list	*replaced_prev;

	replaced_prev = ft_lstlast(expanded_token);
	ft_lstreplace(prev_token, current_token, expanded_token);
	if (!prev_token)
		*tokens = expanded_token;
	return (replaced_prev);
}

static t_list	*remove_current_token(t_list *tokens, t_list *prev_token,
		t_list *current_token, t_list *next_token)
{
	if (prev_token)
		prev_token->next = next_token;
	else
		tokens = next_token;
	free(current_token->content);
	free(current_token);
	return (tokens);
}
