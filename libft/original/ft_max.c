/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:09:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:58:47 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_int(int a, int b, int *m)
{
	if (a <= b)
		*m = b;
	else
		*m = a;
	return (*m);
}

long	ft_max_long(long a, long b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

long long	ft_max_long_long(long long a, long long b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

size_t	ft_max_size_t(size_t a, size_t b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}
