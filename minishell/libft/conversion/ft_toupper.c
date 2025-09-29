/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:47:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 11:36:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
// 	for (int i = 0; i < 26; i++)
// 	{
// 		printf("%2d :%c -> %c\n", i, (char)('a'+i),(char)ft_toupper('a'+i))
// 		printf("%2d :%c -> %c\n", i, (char)('a'+i),(char)toupper('a'+i))
// 	}
// 	printf("\n");
// 	for (int i = 0; i < 26; i++)
// 	{
// 		printf("%2d :%c -> %c\n", i, (char)('A'+i),(char)ft_toupper('A'+i))
// 		printf("%2d :%c -> %c\n", i, (char)('A'+i),(char)toupper('A'+i))
// 	}
// 	return (0);
// }
