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

#ifndef VARIABLE_EXPAND_INTERNAL_H
# define VARIABLE_EXPAND_INTERNAL_H

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
int			expand_push_token(t_expand_store *store,
				t_shell_table *shell_table);
void		expand_free_store(t_expand_store *store);
int			expand_add_buffer(t_expand_store *store, char c);
size_t		get_key_length(const char *from);

// state handler
void		expand_in_normal(t_shell_table *shell_table, t_expand_store *store,
				t_expand_state *state, char **current);
void		expand_in_double_quote(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
void		expand_in_single_quote(t_shell_table *shell_table,
				t_expand_store *store, t_expand_state *state, char **current);
t_list		*expand_on_success(t_expand_store *store, char *token);
t_list		*expand_on_error(t_expand_store *store, char *token);

#endif
