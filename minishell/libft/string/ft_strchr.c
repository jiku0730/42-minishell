/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:03:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:50:08 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locate first occurrence of character in string */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == 0)
		return ((char *)s);
	return (NULL);
}

// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	test_strchr(const char *s, int c, const char *test_name)
// {
// 	char	*ft_result;
// 	char	*std_result;

// 	ft_result = ft_strchr(s, c);
// 	std_result = strchr(s, c);
// 	printf("Test: %s\n", test_name);
// 	printf("Search string: \"%s\", Search character: '%c' (ASCII: %d)\n", s,
// 		c >= 32 && c <= 126 ? c : ' ', c);
// 	if (ft_result == NULL && std_result == NULL)
// 		printf("Result: Both NULL (match)\n");
// 	else if (ft_result != NULL && std_result != NULL)
// 		printf("Result: ft_strchr = %p, strchr = %p (Match: %s)\n",
// 			(void *)ft_result, (void *)std_result,
// 			ft_result == std_result ? "Yes" : "No");
// 	else
// 		printf("Result: ft_strchr = %p, strchr = %p (Mismatch!)\n",
// 			(void *)ft_result, (void *)std_result);
// 	printf("\n");
// }

// int	main(void)
// {
// 	// Test Case 1: Normal character search
// 	test_strchr("Hello, world!", 'w', "Normal character search");
// 	// Test Case 2: First character of the string
// 	test_strchr("Hello, world!", 'H', "First character of the string");
// 	// Test Case 3: Last character of the string
// 	test_strchr("Hello, world!", '!', "Last character of the string");
// 	// Test Case 4: Character not present in the string
// 	test_strchr("Hello, world!", 'z', "Character not present");
// 	// Test Case 5: NULL terminator search
// 	test_strchr("Hello, world!", '\0', "NULL terminator search");
// 	// Test Case 6: Character appearing multiple times
// 	test_strchr("Hello, world!", 'l', "Character appearing multiple times");
// 	// Test Case 7: Search in an empty string
// 	test_strchr("", 'a', "Search in an empty string");
// 	// Test Case 8: Search for NULL character in an empty string
// 	test_strchr("", '\0', "Search for NULL character in an empty string");
// 	return (0);
// }
