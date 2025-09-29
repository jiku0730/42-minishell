/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:09:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/18 19:32:11 by kjikuhar         ###   ########.fr       */
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

// #include <stdio.h>

// int main(void)
// {
// 	int tabs[] = {0, 1, 2, 3, 4, 5};

// 	printf("%d\n", ft_max_int(tabs[3], tabs[1]));
// }
