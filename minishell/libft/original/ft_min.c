/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:05:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:58:50 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min_int(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

long	ft_min_long(long a, long b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

long long	ft_min_long_long(long long a, long long b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

size_t	ft_min_size_t(size_t a, size_t b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}
