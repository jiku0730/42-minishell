/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:06:53 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/16 20:20:20 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *strs[] = {"Hello World 42 Tokyo!", "1234567890",
// 					"abcdefghijklmnopqrstuvwxyz"};
// 	for (int i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
// 	{
// 		printf("%10s : %zu\n", strs[i], ft_strlen((const char *)strs[i]));
// 	}
// 	return (0);
// }
