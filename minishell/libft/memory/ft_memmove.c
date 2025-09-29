/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:28:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 21:59:54 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_str;
	const unsigned char	*src_str;

	if (!dest && !src)
		return (NULL);
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	if (dest < src)
		while (n--)
			*dest_str++ = *src_str++;
	else
	{
		src_str += n;
		dest_str += n;
		while (n--)
			*--dest_str = *--src_str;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str[] = "Hello, World!";
// 	char	overlap1[] = "abcdefghijkl";
// 	char	overlap2[] = "0123456789";

// 	// Copy without overlap
// 	printf("Original string: %s\n", str);
// 	ft_memmove(str + 7, "42Tokyo", 7);
// 	printf("After memmove: %s\n", str);

// 	// Copy with overlap (forward copy)
// 	ft_memmove(overlap1 + 3, overlap1, 4);
// 	printf("Overlapping copy (forward): %s\n", overlap1);

// 	// Copy with overlap (backward copy)
// 	ft_memmove(overlap2, overlap2 + 2, 5);
// 	printf("Overlapping copy (backward): %s\n", overlap2);

// 	return (0);
// }
