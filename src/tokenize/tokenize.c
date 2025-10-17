/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:14:04 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 22:55:05 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	initialize(t_token_store *store, t_token_state *state,
				char **current, char *input);

t_list	*tokenize(char *input)
{
	t_token_store	store;
	t_token_state	state;
	char			*current;

	if (!input)
		return (NULL);
	initialize(&store, &state, &current, input);
	while (true)
	{
		if (state == IN_NORMAL)
			in_normal(&store, &state, *current);
		else if (state == IN_DOUBLE_QUOTE)
			in_double_quote(&store, &state, *current);
		else if (state == IN_SINGLE_QUOTE)
			in_single_quote(&store, &state, *current);
		else if (state == IN_OPERATOR)
			in_operator(&store, &state, *current);
		else if (state == ON_SUCCESS)
			return (on_success(&store, current));
		else if (state == ON_ERROR)
			return (on_error(&store, current));
		current++;
	}
}

static void	initialize(t_token_store *store, t_token_state *state,
		char **current, char *input)
{
	store->tokens = NULL;
	store->buffer = NULL;
	*current = input;
	*state = IN_NORMAL;
	input = NULL;
}
