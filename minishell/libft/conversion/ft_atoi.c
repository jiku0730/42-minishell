/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:08:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/16 16:54:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str == '-')
			sign *= -1;
	num = 0;
	while (ft_isdigit((int)*str))
		num = 10 * num + (*str++ - '0');
	return (sign * num);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str[] = {"123", "-3456789", "  -112", "123", "0123456789",
// 			"10123456789", "10101010101010101010101", "10101010101010",
// 			"10010101010101010101", "9910101010101010101",
// 			"9010101010101010101", "9510101010101010101", "9210101010101010101",
// 			"2147483648", "18446744073709551615"};

// 	for (unsigned int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
// 	{
// 		printf("%i : %20s : %d\n", i, str[i], atoi(str[i]));
// 		printf("%i : %20s : %d\n", i, str[i], ft_atoi(str[i]));
// 		printf("\n");
// 	}
// 	return (0);
// }
