/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_single_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:22:34 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:46:06 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../variable_expand_internal.h"
#include "variable_expand.h"

static void	by_single_quote_end(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);

void	in_single_quote_expand(t_shell_table *shell_table,
		t_expand_store *store, t_expand_state *state, char **current)
{
	if (**current == '\0')
		*state = EXPAND_ON_ERROR;
	else if (**current == '\'')
		by_single_quote_end(shell_table, store, state, current);
	else if (add_buffer_expand(store, **current) == ERROR)
		*state = EXPAND_ON_ERROR;
}

static void	by_single_quote_end(t_shell_table *shell_table,
		t_expand_store *store, t_expand_state *state, char **current)
{
	if (add_buffer_expand(store, **current) == ERROR || push_token_expand(store,
			shell_table) == ERROR)
		*state = EXPAND_ON_ERROR;
	else
		*state = EXPAND_IN_NORMAL;
}
