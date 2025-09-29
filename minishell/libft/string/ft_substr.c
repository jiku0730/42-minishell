/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:00:05 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:08:53 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(start < s_len))
		return (ft_strdup(""));
	if (!(start + len < s_len))
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	test_substr(char const *s, unsigned int start, size_t len,
// 		const char *test_name)
// {
// 	char	*result;

// 	result = ft_substr(s, start, len);
// 	printf("Test: %s\n", test_name);
// 	printf("Original string: \"%s\"\n", s ? s : "(null)");
// 	printf("Start position: %u, Length: %zu\n", start, len);
// 	printf("Result: \"%s\"\n", result ? result : "(null)");
// 	printf("Result length: %zu\n", result ? strlen(result) : 0);
// 	printf("\n");
// 	if (result)
// 		free(result);
// }

// int	main(void)
// {
// 	char	long_str[1000];

// 	// Test Case 1: Basic substring extraction
// 	test_substr("Hello, world!", 7, 5, "Basic substring extraction");
// 	// Test Case 2: Start position beyond string length
// 	test_substr("Hello", 10, 5, "Start position beyond string length");
// 	// Test Case 3: Length longer than remaining string
// 	test_substr("Hello", 2, 10, "Length longer than remaining string");
// 	// Test Case 4: Empty string
// 	test_substr("", 0, 5, "Empty string");
// 	// Test Case 5: Start position at last character
// 	test_substr("Hello", 4, 1, "Start position at last character");
// 	// Test Case 6: Length is zero
// 	test_substr("Hello", 2, 0, "Length zero");
// 	// Test Case 7: Very large length specified
// 	test_substr("Hello", 0, 1000, "Very large length specified");
// 	// Additional test cases
// 	test_substr("Hello, world!", 0, 5, "Extract from start of string");
// 	test_substr("Hello\nworld", 5, 6, "String including newline");
// 	test_substr("Hello\tworld", 5, 6, "String including tab");
// 	test_substr("   Hello   ", 3, 5, "String including spaces");
// 	test_substr("Hello", 0, 0, "Extract zero length from start");
// 	// Boundary tests on string length
// 	test_substr("A", 0, 1, "Extract entire one-character string");
// 	test_substr("AB", 0, 1,
// 		"Extract first character from two-character string");
// 	test_substr("AB", 1, 1,
// 		"Extract second character from two-character string");
// 	// Very long string (memory efficiency test)
// 	memset(long_str, 'X', 999);
// 	long_str[999] = '\0';
// 	test_substr(long_str, 500, 100, "Extract part of very long string");
// 	// Special index cases
// 	test_substr("Hello, world!", 7, 0, "Valid start but zero length");
// 	test_substr("Hello, world!", 12, 1, "Extract last character ('!')");
// 	test_substr("Hello, world!", 13, 0, "Extract zero length at string end");
// 	// String including special characters
// 	test_substr("Hello\"quotes\"", 5, 8, "String including quotes");
// 	test_substr("Hello\\escape", 5, 7, "String including escape character");
// 	// NULL pointer case
// 	test_substr(NULL, 0, 5, "NULL pointer");
// 	return (0);
// }
