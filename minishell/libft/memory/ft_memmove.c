/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:28:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:58:34 by kjikuhar         ###   ########.fr       */
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
