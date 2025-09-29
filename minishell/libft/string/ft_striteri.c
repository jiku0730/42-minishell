/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:04:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:04:53 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// // Function to convert all lowercase letters to uppercase
// void	convert_to_upper(unsigned int i, char *c)
// {
// 	(void)i; // Index is not used
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 'a' + 'A';
// }

// // Function to convert only even-indexed characters to uppercase
// void	convert_even_index_to_upper(unsigned int i, char *c)
// {
// 	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
// 		*c = *c - 'a' + 'A';
// }

// // Function to print each character with its index (for debugging)
// void	print_with_index(unsigned int i, char *c)
// {
// 	printf("[%u]:%c ", i, *c);
// }

// int	main(void)
// {
// 	char	str1[] = "hello world";
// 	char	str2[] = "abcdefghij";
// 	char	str3[] = "42tokyo";
// 	char	str4[] = "";

// 	// Test Case 1: Normal string
// 	printf("Original string: %s\n", str1);
// 	ft_striteri(str1, convert_to_upper);
// 	printf("After converting to uppercase: %s\n", str1);
// 	// Test Case 2: Using another conversion function
// 	printf("\nOriginal string: %s\n", str2);
// 	ft_striteri(str2, convert_even_index_to_upper);
// 	printf("After converting only even indices to uppercase: %s\n", str2);
// 	// Test Case 3: Debugging function
// 	printf("\nOriginal string: %s\n", str3);
// 	printf("Each character with its index: ");
// 	ft_striteri(str3, print_with_index);
// 	printf("\n");
// 	// Test Case 4: Empty string
// 	printf("\nEmpty string test: ");
// 	ft_striteri(str4, convert_to_upper);
// 	printf("Result: \"%s\"\n", str4);
// 	// Test Case 5: NULL pointer and function (should handle gracefully)
// 	printf("\nNULL pointer test (nothing should happen)\n");
// 	ft_striteri(NULL, convert_to_upper);
// 	ft_striteri(str1, NULL);
// 	return (0);
// }
