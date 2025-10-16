/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:14:04 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 00:23:58 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	initialize(char **begin_ptr, char **current_ptr,
				t_token_state *state, char *input);

t_list	*tokenize(char *input)
{
	t_token_store	store;
	t_token_state	state;
	char			*begin_ptr;
	char			*current_ptr;

	if (!input)
		return (NULL);
	init_store(&store);
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
			return (on_success(&store));
		else if (state == ON_ERROR)
			return (on_error(&store));
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
