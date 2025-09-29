/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:07:45 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:54:06 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locate substring in a string with length limit */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!little || !big)
		return (NULL);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0 || little_len > len)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && little[j] && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include "libft.h"
// #include <bsd/string.h>
// #include <stdio.h>
// #include <string.h>

// // Function to display test results
// void	test_strnstr(const char *big, const char *little, size_t len,
// 		const char *test_name)
// {
// 	char	*ft_result;
// 	char	*org_result;

// 	ft_result = ft_strnstr(big, little, len);
// 	org_result = strnstr(big, little, len);
// 	printf("Test: %s\n", test_name);
// 	printf("Target string: \"%s\"\n", big);
// 	printf("Search string: \"%s\"\n", little);
// 	printf("Search length: %zu\n", len);
// 	// Display result pointer as string, or "(null)" if NULL
// 	printf("ft_strnstr result: %s\n", ft_result ? ft_result : "(null)");
// 	printf("strnstr result:    %s\n", org_result ? org_result : "(null)");
// 	printf("Pointer match: %s\n\n", (ft_result == org_result) ? "Yes" : "No");
// }

// int	main(void)
// {
// 	char			str_with_null[] = "Hello\0world";
// 	unsigned char	binary[] = {0x10, 0x20, 0x30, 0x40, 0x50};
// 	unsigned char	pattern[] = {0x30, 0x40};

// 	// Test case 1: Basic search
// 	test_strnstr("Hello, world!", "world", 13, "Basic search");
// 	// Test case 2: Partial search (within limit)
// 	test_strnstr("Hello, world!", "world", 13, "Partial search within limit");
// 	// Test case 3: Partial search (outside limit)
// 	test_strnstr("Hello, world!", "world", 8, "Partial search outside limit");
// 	// Test case 4: Match at beginning
// 	test_strnstr("Hello, world!", "Hello", 13, "Match at beginning");
// 	// Test case 5: Match at end
// 	test_strnstr("Hello, world!", "ld!", 13, "Match at end");
// 	// Test case 6: Non-existent string
// 	test_strnstr("Hello, world!", "xyz", 13, "Non-existent string");
// 	// Test case 7: Empty search string
// 	test_strnstr("Hello, world!", "", 13, "Empty search string");
// 	// Test case 8: Search after NULL character
// 	test_strnstr(str_with_null, "world", 11, "Search after NULL character");
// 	// Test case 9: Binary data
// 	test_strnstr((char *)binary, (char *)pattern, 5, "Binary data");
// 	// Test case 10: Search with length 0
// 	test_strnstr("Hello, world!", "Hello", 0, "Search with length 0");
// 	// Test case 11: Duplicate pattern
// 	test_strnstr("abababab", "abab", 8, "Duplicate pattern");
// 	return (0);
// }
