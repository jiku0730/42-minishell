/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:49:36 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:54:28 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

static void	by_last(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
static void	by_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);

void		expand_in_normal(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (current == '\0')
		by_last(shell_table, store, state, current);
	else if (current == '"' || current == '\'')
		by_quote(shell_table, store, state, current);
	else if (current == '$')
		by_dollar(shell_table, store, state, current);
	else if (expand_add_buffer(store, current) == ERROR)
		*state = EXPAND_ON_ERROR;
}

static void	by_last(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	(void)current;
	if (expand_push_token(store, shell_table) == ERROR)
		*state = EXPAND_ON_ERROR;
	else
		*state = EXPAND_ON_SUCCESS;
}

static void	by_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (expand_push_token(store, shell_table) == ERROR || expand_add_buffer(store, current) == ERROR)
		*state = EXPAND_ON_ERROR;
	else if (current == '"')
		*state = EXPAND_IN_DOUBLE_QUOTE;
	else
		*state = EXPAND_IN_SINGLE_QUOTE;
}

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (expand_push_token(store, shell_table) == ERROR || expand_add_buffer(store, current) == ERROR)
		*state = EXPAND_ON_ERROR;
}
