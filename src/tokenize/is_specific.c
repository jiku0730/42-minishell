/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specific.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:15:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 21:29:08 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

bool	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

bool	is_operator_char(char c)
{
	if (c == '&' || c == '|' || c == '<' || c == '>')
		return (true);
	return (false);
}

size_t	operator_length(const char *str)
{
	if (ft_strncmp(str, "<<<", 3) == 0 || \
		ft_strncmp(str, "<<-", 3) == 0)
		return (3);
	if (ft_strncmp(str, "&&", 2) == 0 || \
		ft_strncmp(str, "||", 2) == 0 || \
		ft_strncmp(str, "<<", 2) == 0 || \
		ft_strncmp(str, ">>", 2) == 0 || \
		ft_strncmp(str, ">&", 2) == 0 || \
		ft_strncmp(str, "<&", 2) == 0 || \
		ft_strncmp(str, ">|", 2) == 0 || \
		ft_strncmp(str, "<>", 2) == 0)
		return (2);
	if (is_operator_char(str[0]))
		return (1);
	return (0);
}

bool	is_operator(const char *str)
{
	if (operator_length(str) > 0)
		return (true);
	return (false);
}

bool	is_parenthesis(char c)
{
	if (c == '(' || c == ')')
		return (true);
	return (false);
}
