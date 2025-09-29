/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:20:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/02 23:13:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return ((unsigned)c - 0x20 < 0x5f);
}

// #include <stdio.h>

// int main(void)
// {
// 	for (int i = -5; i <= 258; i++)
// 	{
// 		char *str = (ft_isprint(i) == 1) ? "OKKK" : "NG";
// 		printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	}
// 	return (0);
// }
