/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:55:17 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 21:28:16 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"

t_list *variable_expand(t_list *tokens, t_shell_table *shell_table)
{
	t_list	*prev_token;
	t_list	*current_token;
	t_list	*expanded_token;

	current_token = tokens;
	prev_token = NULL;
	while (current_token)
	{
		expanded_token = expand_token(current_token->content, shell_table);
		if (!expanded_token)
			return (NULL);
		ft_lstswap(prev_token, current_token, expanded_token);
		if (!prev_token)
			tokens = expanded_token;
		prev_token = expanded_token;
		current_token = current_token->next;
	}
	return (tokens);
}

char	*expand_token(char *token, t_shell_table *shell_table)
{
	t_list *expanded_token;
	t_expand_state	state;
	char	*expanded_str;

	state = IN_NORMAL;
	while (true)
	{
		if (state == IN_NORMAL)
			in_normal();
		else if (state == IN_DOUBLE_QUOTE)
			in_double_quote();
		else if (state == IN_SINGLE_QUOTE)
			in_single_quote();
	}
	expanded_token = ft_lstnew(expanded_str);
	if (!expanded_token)
		return (NULL);
	
}

void		in_normal()
{
}

void		in_double_quote()
{
}

void		in_single_quote()
{
}
