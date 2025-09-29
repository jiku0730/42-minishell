/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:45:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 21:58:55 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* When memory regions may overlap, you should use memmove instead of memcpy */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_str;
	const unsigned char	*src_str;

	if (n == 0 || dest == src)
		return (dest);
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	while (n--)
		*(dest_str++) = *(src_str++);
	return (dest);
}
// #include <assert.h>
// #include <stdlib.h>
// #include <string.h>

// /* MEMCPY_01: Regular copy (5 bytes) */
// static void	test_memcpy_short(void)
// {
// 	const char	*src = "abcde";
// 	char		dest[8] = {0};

// 	assert(ft_memcpy(dest, src, 5) == dest);
// 	assert(memcmp(dest, src, 5) == 0);
// }

// /* MEMCPY_02: No change when n==0 */
// static void	test_memcpy_n_zero(void)
// {
// 	const char	*src = "xyz";
// 	char		dest[8] = "XXXX";

// 	assert(ft_memcpy(dest, src, 0) == dest);
// 	assert(strcmp(dest, "XXXX") == 0); /* content unchanged */
// }

// /* MEMCPY_03: Copy including '\0' */
// static void	test_memcpy_with_nullbyte(void)
// {
// 	const char	*src = "Hello\0World";
// 	char		dest[12] = {0};

// 	size_t n = strlen(src) + 1; /* up to '\0' */
// 	assert(ft_memcpy(dest, src, n) == dest);
// 	assert(memcmp(dest, src, n) == 0);
// }

// /* MEMCPY_04: dest == src */
// static void	test_memcpy_same_pointer(void)
// {
// 	char	buffer[6] = "ABCDE";

// 	assert(ft_memcpy(buffer, buffer, 5) == buffer);
// 	assert(memcmp(buffer, "ABCDE", 5) == 0);
// }

// /* MEMCPY_05: Large capacity 2048 bytes */
// static void	test_memcpy_large_block(void)
// {
// 	size_t			n;
// 	unsigned char	*src;
// 	unsigned char	*dest;

// 	n = 2048;
// 	src = malloc(n);
// 	dest = malloc(n);
// 	assert(src && dest);
// 	memset(src, 0xAA, n);
// 	memset(dest, 0x00, n);
// 	assert(ft_memcpy(dest, src, n) == dest);
// 	assert(memcmp(dest, src, n) == 0);
// 	free(src);
// 	free(dest);
// }

// /* MEMCPY_06: dest==NULL && src==NULL && n==0 */
// static void	test_memcpy_null_null_zero(void)
// {
// 	assert(ft_memcpy(NULL, NULL, 0) == NULL);
// }

// // /* MEMCPY_07: dest==NULL && src!=NULL && n==0 */
// // static void	test_memcpy_null_nonull_zero(void)
// // {
// // 	assert(ft_memcpy(NULL, "a", 0) == NULL);
// // }

// // /* MEMCPY_08: dest!=NULL && src==NULL && n==0 */
// // static void	test_memcpy_nonull_null_zero(void)
// // {
// // 	char	*dst;
// // 	dst = malloc(32);
// // 	assert(ft_memcpy(dst, NULL, 0) == NULL);
// // 	free(dst);
// // }

// int	main(void)
// {
// 	// ft_memcpy(NULL, NULL, 1);
// 	// memcpy(NULL, NULL, 1);
// 	// ft_memcpy(NULL, NULL, 0);
// 	// memcpy(NULL, NULL, 0);
// 	test_memcpy_short();
// 	test_memcpy_n_zero();
// 	test_memcpy_with_nullbyte();
// 	test_memcpy_same_pointer();
// 	test_memcpy_large_block();
// 	test_memcpy_null_null_zero();
// 	// test_memcpy_null_nonull_zero();
// 	// test_memcpy_nonull_null_zero();
// 	return (0);
// }
