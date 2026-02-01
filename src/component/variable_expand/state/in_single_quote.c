/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_single_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:22:34 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:22:51 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);

void		in_single_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (current == '\0')
		*state = ON_ERROR;
	else if (current == '$')
		by_dollar(shell_table, store, state, current);
	else if (add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
	else if (current == '"')
		*state = IN_NORMAL;
}

static void	by_dollar(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current)
{
	if (push_token(store, shell_table) == ERROR || add_buffer(store, current) == ERROR)
		*state = ON_ERROR;
}
