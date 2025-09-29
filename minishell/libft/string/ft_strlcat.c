/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:41:28 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 11:54:38 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	dst_length = ft_strnlen(dst, size);
	src_length = ft_strlen(src);
	i = 0;
	if (dst_length >= size)
		return (dst_length + src_length);
	while (src[i] && dst_length + i + 1 < size)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dest[200] = "12345";
// 	char	src[200] = "1234567890";
// 	size_t		result;

// 	printf("%zu\n", ft_strnlen(dest, 3));
// 	result = ft_strlcat(dest, src, 3);
// 	printf("dest = %s\n", dest);
// 	printf("result = %zu\n", result);
// 	return (0);
// }
