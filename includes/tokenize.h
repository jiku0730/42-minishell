/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:25 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 14:20:21 by urassh           ###   ########.fr       */
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
	IN_QUOTE,
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

// is specific
bool		is_quote_char(const char c);
bool		is_operator_char(const char c);

// store
int			push_token(t_token_store *store);
int			add_buffer(t_token_store *store, const char c);
void		free_store(t_token_store *store);

// state handler
void		in_normal(t_token_store *store, t_token_state *state,
				const char current);
void		in_quote(t_token_store *store, t_token_state *state,
				const char current);
void		in_operator(t_token_store *store, t_token_state *state,
				const char current);
t_list		*on_success(t_token_store *store, char *input);
t_list		*on_error(t_token_store *store, char *input);

#endif
