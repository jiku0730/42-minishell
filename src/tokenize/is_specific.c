/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specific.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:15:00 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 14:33:34 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

bool	is_quote(char c)
{
	if (c == '"')
		return (true);
	if (c == '\'')
		return (true);
	return (false);
}

bool	is_operator(char c)
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
