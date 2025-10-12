/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:14:04 by urassh            #+#    #+#             */
/*   Updated: 2025/10/13 01:38:04 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	initialize(char **begin_ptr, char **current_ptr,
				t_token_state *state, char *input);

t_list	*tokenize(char *input)
{
	t_list			*token_list;
	t_token_state	state;
	char			*begin_ptr;
	char			*current_ptr;

	if (!input)
		return (NULL);
	token_list = NULL;
	initialize(&begin_ptr, &current_ptr, &state, input);
	while (true)
	{
		if (state == IN_NORMAL)
			in_normal(&token_list, &begin_ptr, &current_ptr, &state);
		else if (state == IN_DOUBLE_QUOTE)
			in_double_quote(&token_list, &begin_ptr, &current_ptr, &state);
		else if (state == IN_SINGLE_QUOTE)
			in_single_quote(&token_list, &begin_ptr, &current_ptr, &state);
		else if (state == IN_OPERATOR)
			in_operator(&token_list, &begin_ptr, &current_ptr, &state);
		else if (state == ON_SUCCESS)
			return (on_success(&token_list));
		else if (state == ON_ERROR)
			return (on_error(&token_list));
		current_ptr++;
	}
}

static void	initialize(char **begin_ptr, char **current_ptr,
		t_token_state *state, char *input)
{
	*begin_ptr = input;
	*current_ptr = input;
	*state = IN_NORMAL;
}
