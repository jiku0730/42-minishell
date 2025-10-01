/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:55:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:57:13 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert the integer 'n'to a ASCII string */
static int	number_len_(int number)
{
	int	number_len;

	number_len = 1;
	if (number == INT_MIN)
	{
		return (11);
	}
	if (number < 0)
	{
		number *= -1;
		number_len++;
	}
	while (number >= 10)
	{
		number /= 10;
		number_len++;
	}
	return (number_len);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest_str;
	int		i;

	dest_str = malloc(sizeof(char) * (number_len_(n) + 1));
	if (!dest_str)
		return (NULL);
	if (n == -2147483648)
	{
		return (ft_strcpy(dest_str, "-2147483648"));
	}
	i = number_len_(n) - 1;
	if (n < 0)
	{
		dest_str[0] = '-';
		n *= -1;
	}
	dest_str[i + 1] = '\0';
	while (n >= 10)
	{
		dest_str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	dest_str[i] = n % 10 + '0';
	return (dest_str);
}
