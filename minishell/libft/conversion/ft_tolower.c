/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:47:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 11:36:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
// 	for (int i = 0; i < 26; i++)
// 	{
// 		printf("%2d :%c -> %c\n", i,(char)('a'+i),(char)ft_olower('a'+i))
// 		printf("%2d :%c -> %c\n", i,(char)('a'+i),(char)olower('a'+i))
// 	}
// 	printf("\n");
// 	for (int i = 0; i < 26; i++)
// 	{
// 		printf("%2d :%c -> %c\n", i,(char)('A'+i),(char)ft_olower('A'+i))
// 		printf("%2d :%c -> %c\n", i,(char)('A'+i),(char)olower('A'+i))
// 	}
// 	return (0);
// }
