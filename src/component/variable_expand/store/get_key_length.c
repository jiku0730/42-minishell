/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:44:15 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 16:28:26 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"

static bool	support_special_char(const char c);

size_t	get_key_length(const char *from)
{
	size_t	i;

	if (!from || from[0] == '\0')
		return (0);
	if (support_special_char(from[0]) || ft_isdigit(from[0]))
		return (1);
	i = 0;
	while (from[i] != '\0')
	{
		if (ft_isalnum((unsigned char)from[i]) || from[i] == '_')
			i++;
		else
			break ;
	}
	return (i);
}

static bool	support_special_char(const char c)
{
	if (c == '?' || c == '$' || c == '#' || c == '*' || c == '@' || c == '-'
		|| c == '!')
		return (true);
	return (false);
}
