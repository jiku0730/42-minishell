/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:06 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:15:01 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../expand_variable_internal.h"
#include "expand.h"

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
static void	by_double_quote_end(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
static void	add_buffer_with_expanded(t_expand_store *store,
				t_expand_state *state, char *expanded);

void	in_double_quote_expand(t_shell_table *shell_table,
		t_expand_store *store, t_expand_state *state, char **current)
{
	if (**current == '\0')
		*state = EXPAND_ON_ERROR;
	else if (**current == '$')
		by_dollar(shell_table, store, state, current);
	else if (**current == '"')
		by_double_quote_end(shell_table, store, state, current);
	else if (add_buffer_expand(store, **current) == ERROR)
		*state = EXPAND_ON_ERROR;
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

static void	by_double_quote_end(t_shell_table *shell_table,
		t_expand_store *store, t_expand_state *state, char **current)
{
	if (add_buffer_expand(store, **current) == ERROR || push_token_expand(store,
			shell_table) == ERROR)
		*state = EXPAND_ON_ERROR;
	else
		*state = EXPAND_IN_NORMAL;
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
