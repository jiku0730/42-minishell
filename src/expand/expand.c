/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:16:33 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 22:20:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_list	*expand(t_list *tokens, t_shell_table *shell_table, \
	int last_exit_status)
{
	tokens = expand_tilde(tokens, shell_table);
	if (!tokens)
		return (NULL);
	tokens = expand_question(tokens, last_exit_status);
	if (!tokens)
		return (NULL);
	tokens = expand_parameter(tokens, shell_table);
	if (!tokens)
		return (NULL);
	tokens = expand_wildcard(tokens);
	if (!tokens)
		return (NULL);
	tokens = expand_remove_quotes(tokens);
	if (!tokens)
		return (NULL);
	return (tokens);
}
