/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand_private.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_EXPAND_PRIVATE_H
# define VARIABLE_EXPAND_PRIVATE_H

# include "variable_expand.h"

typedef enum e_expand_state
{
	IN_NORMAL,
	IN_DOUBLE_QUOTE,
	IN_SINGLE_QUOTE,
	ON_ERROR,
	ON_SUCCESS,
}			t_expand_state;

typedef struct s_expand_store
{
	t_list	*tokens;
	t_list	*buffer;
	size_t	skip_count;
}			t_expand_store;

// store
int			push_token(t_expand_store *store,
				t_shell_table *shell_table);
void		free_store(t_expand_store *store);
int			add_buffer(t_expand_store *store, char c);
size_t		get_key_length(const char *from);

// state handler
void		in_normal(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
void		in_double_quote(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
void		in_single_quote(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
t_list		*on_success(t_expand_store *store, char *token);
t_list		*on_error(t_expand_store *store, char *token);

#endif
