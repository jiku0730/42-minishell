/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:49:36 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:21:05 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"

static void	by_last(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
static void	by_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);

void		in_normal(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (current == '\0')
		by_last(shell_table, store, state, current);
	else if (current == '"' || current == '\'')
		by_quote(shell_table, store, state, current);
	else if (current == '$')
		by_dollar(shell_table, store, state, current);
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
}

static void	by_last(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	(void)current;
	if (push_token(store, shell_table) == ERROR)
		*state = ON_ERROR;
	else
		*state = ON_SUCCESS;
}

static void	by_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_DOUBLE_QUOTE;
	else
		*state = IN_SINGLE_QUOTE;
}

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (push_token(store, shell_table) == ERROR || add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
}
