/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:49:36 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:15:04 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../variable_expand_internal.h"
#include "variable_expand.h"

static void	by_last(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
static void	by_quote(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
static void	by_dollar(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
static void	add_buffer_with_expanded(t_expand_store *store,
				t_expand_state *state, char *expanded);

void	in_normal_expand(t_shell_table *shell_table, t_expand_store *store,
		t_expand_state *state, char **current)
{
	if (**current == '\0')
		by_last(shell_table, store, state, current);
	else if (**current == '"' || **current == '\'')
		by_quote(shell_table, store, state, current);
	else if (**current == '$')
		by_dollar(shell_table, store, state, current);
	else if (add_buffer_expand(store, **current) == ERROR)
		*state = EXPAND_ON_ERROR;
}

static void	by_last(t_shell_table *shell_table, t_expand_store *store,
		t_expand_state *state, char **current)
{
	(void)current;
	if (push_token_expand(store, shell_table) == ERROR)
		*state = EXPAND_ON_ERROR;
	else
		*state = EXPAND_ON_SUCCESS;
}

static void	by_quote(t_shell_table *shell_table, t_expand_store *store,
		t_expand_state *state, char **current)
{
	if (push_token_expand(store, shell_table) == ERROR
		|| add_buffer_expand(store, **current) == ERROR)
		*state = EXPAND_ON_ERROR;
	else if (**current == '"')
		*state = EXPAND_IN_DOUBLE_QUOTE;
	else
		*state = EXPAND_IN_SINGLE_QUOTE;
}

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store,
		t_expand_state *state, char **current)
{
	size_t	key_length;
	char	*key;
	char	*expanded;

	key_length = get_key_length(*current + 1);
	if (key_length == 0)
	{
		if (add_buffer_expand(store, **current) == ERROR)
			*state = EXPAND_ON_ERROR;
		return ;
	}
	key = ft_substr(*current, 1, key_length);
	if (!key)
	{
		*state = EXPAND_ON_ERROR;
		return ;
	}
	expanded = st_search(shell_table, key);
	free(key);
	add_buffer_with_expanded(store, state, expanded);
	if (*state == EXPAND_ON_ERROR)
		return ;
	store->skip_count = key_length;
}

static void	add_buffer_with_expanded(t_expand_store *store,
		t_expand_state *state, char *expanded)
{
	size_t	i;

	if (!expanded)
		return ;
	i = 0;
	while (expanded[i] != '\0')
	{
		if (add_buffer_expand(store, expanded[i]) == ERROR)
		{
			*state = EXPAND_ON_ERROR;
			return ;
		}
		i++;
	}
}
