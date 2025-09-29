/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:20:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:03:04 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASCII_MAX 0x7F /* 127 */

int	ft_isascii(int c)
{
	return ((unsigned)c <= ASCII_MAX);
}

// bit mask
// int	ft_ft_isascii(int c)
// {
// 	return (!(c & ~0x7f));
// // }
// #include <stdio.h>

// int	ft_isascii(int c)
// {
// 	return ((unsigned)c <= 127);
// }

// int	isascii(int c)
// {
// 	return ((c >= 0 && c <= 127) ? 1 : 0);
// }

// int main(void)
// {
// 	for (int i = -5; i <= 130; i++)
// 	{
// 		char *str = (ft_isascii(i) == 1) ? "OKKKKK" : "NG";
// 		printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	}
// 	return (0);
// }
// #include <stdio.h>
// #include <time.h>

// // Implementation 1: Range Check
// int	isascii_range(int c)
// {
// 	return (c >= 0 && c <= 127);
// }

// // Implementation 2: Bit Mask
// int	isascii_bitmask(int c)
// {
// 	return (!(c & ~0x7f));
// }

// // Implementation 3: Constant Comparison
// int	isascii_unsigned(int c)
// {
// 	return ((unsigned)c <= 127);
// }

// // Implementation 4: Table Lookup
// int	isascii_table(int c)
// {
// 	static const char ascii_table[128] = {[0 ... 127] = 1};
// 		// Set ASCII range to 1
// 	return ((c >= 0 && c < 128) ? ascii_table[c] : 0);
// }

// #define ITERATIONS 1000000000 // 1 billion iterations

// void	benchmark(const char *name, int (*func)(int))
// {
// 	int	result;

// 	clock_t start, end;
// 	result = 0;
// 	start = clock();
// 	for (int i = 0; i < ITERATIONS; i++)
// 	{
// 		result += func(i % 256); // Loop through range of 256
// 	}
// 	end = clock();
// 	printf("%s: %f seconds\n", name, (double)(end - start) / CLOCKS_PER_SEC);
// }

// int	main(void)
// {
// 	printf("Benchmarking isascii implementations...\n");
// 	benchmark("Range Check", isascii_range);
// 	benchmark("Bitmask", isascii_bitmask);
// 	benchmark("Unsigned Comparison", isascii_unsigned);
// 	benchmark("Table Lookup", isascii_table);
// 	return (0);
// }
