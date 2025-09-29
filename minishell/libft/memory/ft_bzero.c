/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:46:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 11:36:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <strings.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	strs[][30] = {"Hello World 42 Tokyo!"};

// 	for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
// 	{
// 		printf("%s\n", strs[i]);
// 		// bzero(strs[i], 2);
// 		ft_bzero(strs[i], 5);
// 		for (size_t j = 0; j < 30; j++)
// 		{
// 			if (strs[i][j] == '\0')
// 				printf("%s", "\\0");
// 			else
// 				printf("%c", strs[i][j]);
// 		}
// 		printf("%c", '\n');
// 	}
// 	return (0);
// }
