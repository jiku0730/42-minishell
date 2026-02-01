/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:37:05 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:40:46 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "constants.h"
# include "libft.h"
# include "shell_table.h"

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
}			t_expand_store;

t_list *variable_expand(t_list *tokens, t_shell_table *shell_table);

// store
int			push_token(t_expand_store *store, t_shell_table *shell_table);
int			add_buffer(t_expand_store *store, char c);

void		in_normal(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
void		in_double_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
void		in_single_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
t_list		*on_success(t_expand_store *store, char *token);
t_list		*on_error(t_expand_store *store, char *token);

#endif
