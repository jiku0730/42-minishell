/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_PRIVATE_H
# define TOKENIZE_PRIVATE_H

# include "tokenize.h"
# include "constants.h"
# include <unistd.h>

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

// is specific
bool		is_quote(char c);
bool		is_operator_char(char c);
bool		is_operator(const char *str);
size_t		operator_length(const char *str);
bool		is_parenthesis(char c);

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
