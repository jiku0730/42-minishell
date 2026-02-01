/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_double_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:06 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:21:53 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
static void	by_double_quote_end(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);

void		expand_in_double_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (current == '\0')
		*state = EXPAND_ON_ERROR;
	else if (current == '$')
		by_dollar(shell_table, store, state, current);
	else if (current == '"')
		by_double_quote_end(shell_table, store, state, current);
	else if (expand_add_buffer(store, current) == ERROR)
		*state = EXPAND_ON_ERROR;
}

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (expand_push_token(store, shell_table) == ERROR || expand_add_buffer(store, current) == ERROR)
		*state = EXPAND_ON_ERROR;
}

static void	by_double_quote_end(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (expand_push_token(store, shell_table) == ERROR || expand_add_buffer(store, current) == ERROR)
		*state = EXPAND_ON_ERROR;
	else
		*state = EXPAND_IN_NORMAL;
}
