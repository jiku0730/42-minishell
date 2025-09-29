/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:23:04 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/07 20:26:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// int main(void)
// {
// 	int a = 42;
// 	int b = 24;

// 	printf("Before: a = %2d, b = %2d\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("After : a = %2d, b = %2d\n", a, b);
// 	return (0);
// }
