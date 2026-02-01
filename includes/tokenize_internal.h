/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_INTERNAL_H
# define TOKENIZE_INTERNAL_H

# include "libft.h"

typedef enum e_token_state
{
	IN_NORMAL,
	IN_DOUBLE_QUOTE,
	IN_SINGLE_QUOTE,
	IN_OPERATOR,
	ON_SUCCESS,
	ON_ERROR,
}			t_token_state;

typedef struct s_token_store
{
	t_list	*tokens;
	t_list	*buffer;
}			t_token_store;

// store
int			push_token(t_token_store *store);
int			add_buffer(t_token_store *store, char c);
void		free_store(t_token_store *store);

// state handler
void		in_normal(t_token_store *store, t_token_state *state, char current);
void		in_double_quote(t_token_store *store, t_token_state *state,
				char current);
void		in_single_quote(t_token_store *store, t_token_state *state,
				char current);
void		in_operator(t_token_store *store, t_token_state *state,
				char current);
t_list		*on_success(t_token_store *store, char *input);
t_list		*on_error(t_token_store *store, char *input);

#endif
