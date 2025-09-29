/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:45:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:58:30 by kjikuhar         ###   ########.fr       */
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
