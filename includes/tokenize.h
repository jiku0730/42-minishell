/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:25 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 22:49:29 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "constants.h"
# include "libft.h"
# include <stdlib.h>

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

t_list		*tokenize(char *input);

// operator
bool		is_operator(const char *str);
bool		is_operator_char(const char c);

// store
int			push_token(t_token_store *store);
int			add_buffer(t_token_store *store, const char c);
void		free_store(t_token_store *store);

// state handler
void		in_normal(t_token_store *store, t_token_state *state,
				const char current);
void		in_double_quote(t_token_store *store, t_token_state *state,
				const char current);
void		in_single_quote(t_token_store *store, t_token_state *state,
				const char current);
void		in_operator(t_token_store *store, t_token_state *state,
				const char current);
t_list		*on_success(t_token_store *store, char *current);
t_list		*on_error(t_token_store *store, char *current);

#endif
