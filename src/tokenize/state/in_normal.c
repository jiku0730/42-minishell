/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/13 02:01:23 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	by_last(t_list **token_list, char **begin_ptr, char **current_ptr,
				t_token_state *state);
static void	by_space(t_list **token_list, char **begin_ptr, char **current_ptr,
				t_token_state *state);
static void	by_quote(t_list **token_list, char **begin_ptr, char **current_ptr,
				t_token_state *state);
static void	by_operator(t_list **token_list, char **begin_ptr,
				char **current_ptr, t_token_state *state);

void	in_normal(t_list **token_list, char **begin_ptr, char **current_ptr,
		t_token_state *state)
{
	if (!**current_ptr)
		by_last(token_list, begin_ptr, current_ptr, state);
	else if (ft_isspace(**current_ptr))
		by_space(token_list, begin_ptr, current_ptr, state);
	else if (ft_strncmp(*current_ptr, "\"", 1) == 0 || ft_strncmp(*current_ptr,
			"'", 1) == 0)
		by_quote(token_list, begin_ptr, current_ptr, state);
	else if (is_operator(*current_ptr))
		by_operator(token_list, begin_ptr, current_ptr, state);
}

static void	by_last(t_list **token_list, char **begin_ptr, char **current_ptr,
		t_token_state *state)
{
	size_t	len;
	char	*token;

	if (*begin_ptr < *current_ptr)
	{
		len = *current_ptr - *begin_ptr;
		token = ft_substr(*begin_ptr, 0, len);
		push_token(token_list, token);
	}
	*state = ON_SUCCESS;
}

static void	by_space(t_list **token_list, char **begin_ptr, char **current_ptr,
		t_token_state *state)
{
	size_t	len;
	char	*token;

	if (*begin_ptr < *current_ptr)
	{
		len = *current_ptr - *begin_ptr;
		token = ft_substr(*begin_ptr, 0, len);
		push_token(token_list, token);
	}
	*begin_ptr = *current_ptr + 1;
	*state = IN_NORMAL;
}

static void	by_quote(t_list **token_list, char **begin_ptr, char **current_ptr,
		t_token_state *state)
{
	size_t	len;
	char	*token;

	if (*begin_ptr < *current_ptr)
	{
		len = *current_ptr - *begin_ptr;
		token = ft_substr(*begin_ptr, 0, len);
		push_token(token_list, token);
	}
	*begin_ptr = *current_ptr + 1;
	if (ft_strncmp(*current_ptr, "\"", 1) == 0)
		*state = IN_DOUBLE_QUOTE;
	if (ft_strncmp(*current_ptr, "\"", 1) == 0)
		*state = IN_SINGLE_QUOTE;
}

static void	by_operator(t_list **token_list, char **begin_ptr,
		char **current_ptr, t_token_state *state)
{
	size_t	len;
	char	*token;

	if (*begin_ptr < *current_ptr)
	{
		len = *current_ptr - *begin_ptr;
		token = ft_substr(*begin_ptr, 0, len);
		push_token(token_list, token);
	}
	*begin_ptr = *current_ptr;
	*state = IN_OPERATOR;
}
