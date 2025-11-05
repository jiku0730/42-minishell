/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specific.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:15:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 14:07:28 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

bool	is_quote_char(const char c)
{
	if (c == '"')
		return (true);
	if (c == '\'')
		return (true);
	return (false);
}

bool	is_operator_char(const char c)
{
	if (c == '&')
		return (true);
	if (c == '|')
		return (true);
	if (c == '<')
		return (true);
	if (c == '>')
		return (true);
	if (c == '(')
		return (true);
	if (c == ')')
		return (true);
	return (false);
}

bool	is_operator(const char *str)
{
	if (ft_strncmp(str, "&&", 2) == 0)
		return (true);
	if (ft_strncmp(str, "||", 2) == 0)
		return (true);
	if (ft_strncmp(str, "<<", 2) == 0)
		return (true);
	if (ft_strncmp(str, ">>", 2) == 0)
		return (true);
	if (ft_strncmp(str, "|", 1) == 0)
		return (true);
	if (ft_strncmp(str, "<", 1) == 0)
		return (true);
	if (ft_strncmp(str, ">", 1) == 0)
		return (true);
	if (ft_strncmp(str, "(", 1) == 0)
		return (true);
	if (ft_strncmp(str, ")", 1) == 0)
		return (true);
	return (false);
}
