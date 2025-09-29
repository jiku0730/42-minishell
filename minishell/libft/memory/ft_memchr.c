/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:30:44 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:02:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;

	us = (const unsigned char *)s;
	while (n--)
	{
		if (*us == (unsigned char)c)
			return ((void *)us);
		us++;
	}
	return (NULL);
}
// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	test_ft_memchr(const void *s, int c, size_t n, const char *test_name)
// {
// 	void	*ft_result;
// 	void	*std_result;

// 	ft_result = ft_memchr(s, c, n);
// 	std_result = memchr(s, c, n);
// 	printf("Test: %s\n", test_name);
// 	printf("ft_memchr result: %p\n", ft_result);
// 	printf("memchr result:    %p\n", std_result);
// 	printf("Match: %s\n\n", (ft_result == std_result) ? "Yes" : "No");
// }

// int	main(void)
// {
// 	char			str1[] = "Hello, world!";
// 	unsigned char	binary[] = {0x10, 0x20, 0x30, 0x40, 0x50};
// 	char			str2[] = "Hello\0world";

// 	// Test case 1: Search for a character in a string
// 	test_ft_memchr(str1, 'w', strlen(str1), "Search for 'w' in 'Hello,
// 		world!'");
// 	// Test case 2: Search for a non-existent character
// 	test_ft_memchr(str1, 'z', strlen(str1), "Search for 'z' in 'Hello,
// 		world!' (non-existent)");
// 	// Test case 3: Search for a character within limited length
// 	test_ft_memchr(str1, 'o', 5, "Search for 'o' in 'Hello, world!' with n=5");
// 	// Test case 4: Search for a character within limited length (not in range)
// 	test_ft_memchr(str1, 'o', 4, "Search for 'o' in 'Hello,
// 		world!' with n=4 (out of range)");
// 	// Test case 5: Search for NULL byte
// 	test_ft_memchr(str1, '\0', strlen(str1) + 1, "Search for '\\0' in 'Hello,
// 		world!'");
// 	// Test case 6: Binary data
// 	test_ft_memchr(binary, 0x30, sizeof(binary),
// 		"Search for 0x30 in binary data");
// 	// Test case 7: Case with n=0
// 	test_ft_memchr("", 'a', 0, "Search for 'a' with n=0");
// 	// Test case 8: Search for character after NULL byte
// 	test_ft_memchr(str2, 'w', 12,
// 		"Search for 'w' after NULL byte in 'Hello\\0world'");
// 	return (0);
// }
