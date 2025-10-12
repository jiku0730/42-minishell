/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:15:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/13 02:20:22 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

bool	is_operator(char *str)
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
