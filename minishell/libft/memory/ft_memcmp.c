/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:41:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:02:43 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_str;
	const unsigned char	*s2_str;

	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_str != *s2_str)
			return (*s1_str - *s2_str);
		s1_str++;
		s2_str++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// void	test_ft_memcmp(const void *s1, const void *s2, size_t n,
// 		const char *test_name)
// {
// 	int	ft_result;
// 	int	std_result;
// 	int	ft_sign;
// 	int	std_sign;

// 	ft_result = ft_memcmp(s1, s2, n);
// 	std_result = memcmp(s1, s2, n);
// 	printf("Test: %s\n", test_name);
// 	printf("ft_memcmp result: %d\n", ft_result);
// 	printf("memcmp result:    %d\n", std_result);
// 	// Check if the result signs are the same
// 	ft_sign = (ft_result > 0) ? 1 : ((ft_result < 0) ? -1 : 0);
// 	std_sign = (std_result > 0) ? 1 : ((std_result < 0) ? -1 : 0);
// 	printf("Match: %s\n\n", (ft_sign == std_sign) ? "Yes" : "No");
// }

// int	main(void)
// {
// 	char			str1[] = "Hello, world!";
// 	char			str3[] = "Hello\0world";
// 	char			str4[] = "Hello\0WORLD";
// 	unsigned char	bin1[] = {0x10, 0x20, 0x30, 0x40};
// 	unsigned char	bin2[] = {0x10, 0x20, 0x50, 0x40};

// // Test case 1: Compare identical strings
// test_ft_memcmp(str1, str1, strlen(str1), "Comparing identical strings");
// // Test case 2: Compare different strings
// char	str2[] = "Hello, World!"; // 'w' changed to 'W'
// test_ft_memcmp(str1, str2, strlen(str1), "Comparing different strings");
// // Test case 3: Strings differing within specified bytes
// test_ft_memcmp("abcdef", "abcDef", 4, "Strings differing within 4 bytes");
// // Test case 4: Strings differing outside of specified bytes
// test_ft_memcmp("abcdef", "abcDef", 3,
// 	"Comparing within 3 bytes (before the difference)");
// // Test case 5: When byte count is zero
// test_ft_memcmp("abc", "def", 0, "Comparison with zero bytes");
// // Test case 6: Comparison including NULL bytes
// test_ft_memcmp(str3, str4, 12, "Strings containing NULL characters");
// // Test case 7: Binary data
// test_ft_memcmp(bin1, bin2, 4, "Comparing binary data");
// return (0);
// }
