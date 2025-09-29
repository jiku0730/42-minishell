/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:11:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/05 13:13:04 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((unsigned)(c | 0x20) - 'a' < 26);
}

// int	ft_isalpha_uc(int c)
// {
// 	return (((unsigned char)c | 32) - 'a' < 26);
// }

// #include <stdio.h>

// int main(void)
// {
// 	for (int i = -5; i <= 130; i++)
// 	{
// 		char *str = (ft_isalpha(i) == 1) ? "OKKKKK" : "NG";
// 		printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	}
// 	// for (int i = -5; i <= 130; i++)
// 	// {
// 	// 	char *str = (ft_isalpha_u(i) == 1) ? "OKKKKK" : "NG";
// 	// 	printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	// }
// 	return (0);
// }
// Optimize processing through bit operations.

// #include <stdio.h>
// #include <time.h>

// int	ft_ft_isalpha(int c) {
// 	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
// }

// int main() {
// 	clock_t start, end;
// 	int count = 1000000000; // Loop 100 million times
// 	int result = 0;

// 	// Test ft_isalpha
// 	start = clock();
// 	for (int i = 0; i < count; i++) {
// 		result += ft_isalpha(i % 256);
// 	}
// 	end = clock();
// 	printf("ft_isalpha: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

// 	// Test ft_ft_isalpha
// 	start = clock();
// 	for (int i = 0; i < count; i++) {
// 		result += ft_ft_isalpha(i % 256);
// 	}
// 	end = clock();
// 	printf("ft_ft_isalpha: %f seconds\n", (double)(end - start)
// 		/ CLOCKS_PER_SEC);

// 	return (result); // Prevent compiler optimization
// }
