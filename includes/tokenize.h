/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:25 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 00:23:35 by urassh           ###   ########.fr       */
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
bool		is_operator(const char *str);

// store
void		init_store(t_token_store *store);
int			push_token(t_token_store *store);
int			add_buffer(t_token_store *store, char c);
void		free_store(t_token_store *store);

// state handler
void		in_normal(t_list **token_list, char **begin_ptr, char **current_ptr,
				t_token_state *state);
void		in_double_quote(t_list **token_list, char **begin_ptr,
				char **current_ptr, t_token_state *state);
void		in_single_quote(t_list **token_list, char **begin_ptr,
				char **current_ptr, t_token_state *state);
void		in_operator(t_list **token_list, char **begin_ptr,
				char **current_ptr, t_token_state *state);
t_list		*on_success(t_token_store *store);
t_list		*on_error(t_token_store *store);

#endif
