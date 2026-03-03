/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 16:28:45 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_VARIABLE_INTERNAL_H
# define EXPAND_VARIABLE_INTERNAL_H

# include "libft.h"
# include "shell_table.h"

typedef enum e_expand_state
{
	EXPAND_IN_NORMAL,
	EXPAND_IN_DOUBLE_QUOTE,
	EXPAND_IN_SINGLE_QUOTE,
	EXPAND_ON_ERROR,
	EXPAND_ON_SUCCESS,
}			t_expand_state;

typedef struct s_expand_store
{
	t_list	*tokens;
	t_list	*buffer;
	size_t	skip_count;
}			t_expand_store;

// store
int			push_token_expand(t_expand_store *store,
				t_shell_table *shell_table);
void		free_store_expand(t_expand_store *store);
int			add_buffer_expand(t_expand_store *store, char c);
size_t		get_key_length(const char *from);

// state handler
void		in_normal_expand(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
void		in_double_quote_expand(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
void		in_single_quote_expand(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
t_list		*on_success_expand(t_expand_store *store, char *token);
t_list		*on_error_expand(t_expand_store *store, char *token);

#endif
