/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:16:33 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 17:54:02 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_list	*expand(t_list *tokens, t_shell_table *shell_table)
{
	tokens = expand_tilde(tokens, shell_table);
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
