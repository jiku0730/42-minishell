/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:25 by urassh            #+#    #+#             */
/*   Updated: 2025/10/13 00:55:05 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

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
}		t_token_state;

t_list	*tokenize(char *input);
void	push_token(t_list **list, char *token);
bool	is_operator(char *str);

void	in_normal(t_list **token_list, char **begin_ptr, char **current_ptr,
			t_token_state *state);
void	in_double_quote(t_list **token_list, char **begin_ptr,
			char **current_ptr, t_token_state *state);
void	in_single_quote(t_list **token_list, char **begin_ptr,
			char **current_ptr, t_token_state *state);
void	in_operator(t_list **token_list, char **begin_ptr, char **current_ptr,
			t_token_state *state);
t_list	*on_success(t_list **token_list);
t_list	*on_error(t_list **token_list);

#endif
