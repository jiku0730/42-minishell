/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:58:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:07:09 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_trimmed_length(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, (unsigned char)s1[start]))
		start++;
	while (end > start && ft_strchr(set, (unsigned char)s1[end - 1]))
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	dest_len;

	if (!s1 || !set)
		return (NULL);
	dest_len = get_trimmed_length(s1, set);
	dest = malloc(dest_len + 1);
	if (!dest)
		return (NULL);
	while (*s1 && ft_strchr(set, (unsigned char)*s1))
		s1++;
	ft_strlcpy(dest, s1, dest_len + 1);
	return (dest);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // テスト関数
// void	run_test(const char *test_name, const char *input, const char *set,
// 		const char *expected_output)
// {
// 	char	*result;

// 	result = ft_strtrim(input, set);
// 	printf("Test: %s\n", test_name);
// 	printf("Input: \"%s\"\n", input);
// 	printf("Set: \"%s\"\n", set);
// 	printf("Expected: \"%s\"\n", expected_output);
// 	printf("Result: \"%s\"\n", result);
// 	if ((result == NULL && expected_output == NULL) || (result
// 			&& expected_output && strcmp((const char *)result,
// 				expected_output) == 0))
// 	{
// 		printf("Status: ✅ Passed\n");
// 	}
// 	else
// 	{
// 		printf("Status: ❌ Failed\n");
// 	}
// 	free(result);
// 	printf("\n");
// // }
// int	main(void)
// {
// 	// Test Case 1: Normal trim
// 	run_test("Normal Trim", "  Hello World!  ", " ", "Hello World!");
// 	// Test Case 2: Empty input string
// 	run_test("Empty Input", "", " ", "");
// 	// Test Case 3: No trim characters present
// 	run_test("No Trim Characters", "HelloWorld", " ", "HelloWorld");
// 	// Test Case 4: Entire input string is trim target
// 	run_test("Full Trim", ".....", ".", "");
// 	// Test Case 5: Empty set
// 	run_test("Empty Set", "   Hello World!   ", "", "   Hello World!   ");
// 	// Test Case 6: Trim only at both ends
// 	run_test("Trim Both Ends", "xxHello World!xx", "x", "Hello World!");
// 	// Test Case 7: Trim including special characters
// 	run_test("Special Characters", "\t\nHello World!\n\t", "\t\n",
// 		"Hello World!");
// 	// Test Case 8: NULL pointer (input string)
// 	run_test("NULL Input", NULL, " ", NULL);
// 	// Test Case 9: NULL pointer (set)
// 	run_test("NULL Set", "  Hello World!  ", NULL, NULL);
// 	// Test Case 10: Partial trim at both ends
// 	run_test("Partial Trim", "xyHello World!yz", "xyz", "Hello World!");
// 	// Test Case 11: Set with numbers
// 	run_test("Numeric Set", "12345Hello12345", "12345", "Hello");
// 	// Test Case 12: Multiple types of trim characters at both ends
// 	run_test("Multiple Trim Characters", "  ***Hello***  ", " *", "Hello");
// 	// Test Case 13: NULL set with non-NULL input
// 	run_test("NULL Set with Non-NULL Input", "Hello World!", NULL, NULL);
// 	// Test Case 14: NULL input with non-NULL set
// 	run_test("NULL Input with Non-NULL Set", NULL, " ", NULL);
// 	// Test Case 15: Different trim characters at each end
// 	run_test("Different Trim Characters", "abcHello World!xyz", "abcxyz",
// 		"Hello World!");
// 	// Test Case 16: Input fully composed of set characters
// 	run_test("Input Fully Matches Set", "aaaaa", "a", "");
// 	// Test Case 17: Set does not overlap with input string
// 	run_test("Set Does Not Match Input", "Hello World!", "xyz", "Hello World!");
// 	// Test Case 18: NULL input and NULL set
// 	run_test("NULL Input and NULL Set", NULL, NULL, NULL);
// 	// Test Case 19: Empty string as set
// 	run_test("Empty Set", "Hello World!", "", "Hello World!");
// 	// Test Case 20: Empty input with non-empty set
// 	run_test("Empty Input with Non-Empty Set", "", "abc", "");
// 	// Test Case 21: Long input string and set
// 	run_test("Long String and Set",
// 		"   This is a very long string for testing purposes.   ", " ",
// 		"This is a very long string for testing purposes.");
// 	// Test Case 22: All characters are trimmed
// 	run_test("All Characters are Trimmed", "xxxxxxxxxx", "x", "");
// 	// Test Case 23: Set includes special characters and numbers
// 	run_test("Set Includes Special Characters", "123Hello World!321", "123!",
// 		"Hello World");
// 	// Test Case 24: Input contains only whitespace
// 	run_test("Whitespace Only Input", "     ", " ", "");
// 	// Test Case 25: Both input string and set are empty
// 	run_test("Empty Input and Empty Set", "", "", "");
// 	return (0);
// }
