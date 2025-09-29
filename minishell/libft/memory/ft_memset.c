/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:36:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 21:59:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Undefined if s == NULL && n > 0. */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uc_dst;

	if (!n)
		return (s);
	uc_dst = (unsigned char *)s;
	while (n--)
		*uc_dst++ = (unsigned char)c;
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	char str[50] = "Hello World 42 Tokyo!";
// 	printf("First string：%s\n", str);

// 	ft_memset(str + 2, '-', 2);
// 	memset(str + 4, '*', 2);
// 	printf("%s\n", str);
// 	return (0);
// }
