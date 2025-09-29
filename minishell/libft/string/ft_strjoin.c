/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:47:54 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:05:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	sum_len;

	if (!s1 || !s2)
		return (NULL);
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (sum_len + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	test_strjoin(char const *s1, char const *s2, const char *test_name)
// {
// 	char	*result;
// 	char	*expected;

// 	result = ft_strjoin(s1, s2);
// 	expected = NULL;
// 	printf("Test: %s\n", test_name);
// 	printf("String 1: \"%s\"\n", s1 ? s1 : "(null)");
// 	printf("String 2: \"%s\"\n", s2 ? s2 : "(null)");
// 	printf("Result: \"%s\"\n", result ? result : "(null)");
// 	if (s1 && s2)
// 	{
// 		expected = malloc(strlen(s1) + strlen(s2) + 1);
// 		if (expected)
// 		{
// 			strcpy(expected, s1);
// 			strcat(expected, s2);
// 			printf("Expected: \"%s\"\n", expected);
// 			printf("Match: %s\n", (result && strcmp(result,
// 						expected) == 0) ? "Yes" : "No");
// 			free(expected);
// 		}
// 	}
// 	else
// 	{
// 		printf("Expected: NULL\n");
// 		printf("Match: %s\n", (!result) ? "Yes" : "No");
// 	}
// 	printf("\n");
// 	if (result)
// 		free(result);
// }

// int	main(void)
// {
// 	char	long_str1[500], long_str2[500];

// 	// 1. Basic string concatenation
// 	test_strjoin("Hello, ", "world!", "Basic string concatenation");
// 	// 2. Concatenation with empty string
// 	test_strjoin("", "Test", "Concatenation with empty and normal string");
// 	// 3. Both strings empty
// 	test_strjoin("", "", "Both strings empty");
// 	// 4. Concatenation including special characters (newline)
// 	test_strjoin("Hello\n", "World", "Concatenation including newline");
// 	// 5. Concatenation including tab character
// 	test_strjoin("Hello\t", "World", "Concatenation including tab");
// 	// 6. Concatenation of long strings
// 	memset(long_str1, 'A', 499);
// 	long_str1[499] = '\0';
// 	memset(long_str2, 'B', 499);
// 	long_str2[499] = '\0';
// 	test_strjoin(long_str1, long_str2, "Concatenation of long strings");
// 	// 7. Concatenation of Japanese (multibyte) strings
// 	test_strjoin("こんにちは", "世界", "Concatenation of Japanese strings");
// 	// 8. Concatenation of numbers and symbols
// 	test_strjoin("12345", "!@#$%", "Concatenation of numbers and symbols");
// 	// 9. Handling NULL pointer in s1
// 	test_strjoin(NULL, "Test", "Handling NULL for s1");
// 	// 10. Handling both NULL
// 	test_strjoin(NULL, NULL, "Handling both NULL");
// 	return (0);
// }
