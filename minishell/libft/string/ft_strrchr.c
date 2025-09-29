/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:03:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/05 18:16:21 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Why: +1 so that '\0' is also searched per strrchr spec */
char	*ft_strrchr(const char *s, int c)
{
	return (ft_memrchr(s, c, ft_strlen(s) + 1));
}
// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	test_strrchr(const char *s, int c, const char *test_name)
// {
// 	char	*ft_result;
// 	char	*std_result;

// 	ft_result = ft_strrchr(s, c);
// 	std_result = strrchr(s, c);
// 	printf("Test: %s\n", test_name);
// 	printf("Search string: \"%s\", Search character: '%c' (ASCII: %d)\n", s,
// 		c >= 32 && c <= 126 ? c : ' ', c);
// 	if (ft_result == NULL && std_result == NULL)
// 		printf("Result: Both NULL (match)\n");
// 	else if (ft_result != NULL && std_result != NULL)
// 		printf("Result: ft_strrchr = %p, strrchr = %p (Match: %s)\n",
// 			(void *)ft_result, (void *)std_result,
// 			ft_result == std_result ? "Yes" : "No");
// 	else
// 		printf("Result: ft_strrchr = %p, strrchr = %p (Mismatch!)\n",
// 			(void *)ft_result, (void *)std_result);
// 	printf("\n");
// }

// int	main(void)
// {
// 	// Test Case 1: Normal character search
// 	test_strrchr("Hello, world!", 'w', "Normal character search");
// 	// Test Case 2: First character of the string
// 	test_strrchr("Hello, world!", 'H', "First character of the string");
// 	// Test Case 3: Last character of the string
// 	test_strrchr("Hello, world!", '!', "Last character of the string");
// 	// Test Case 4: Character not present in the string
// 	test_strrchr("Hello, world!", 'z', "Character not present");
// 	// Test Case 5: NULL terminator search
// 	test_strrchr("Hello, world!", '\0', "NULL terminator search");
// 	// Test Case 6: Character appearing multiple times
// 	test_strrchr("Hello, world!", 'l', "Character appearing multiple times");
// 	// Test Case 7: Search in an empty string
// 	test_strrchr("", 'a', "Search in an empty string");
// 	// Test Case 8: Search for NULL character in an empty string
// 	test_strrchr("", '\0', "Search for NULL character in an empty string");
// 	return (0);
// }
