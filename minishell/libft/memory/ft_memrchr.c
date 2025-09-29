/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:16:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:58:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* search by decrement loop */
void	*ft_memrchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;

	us = (unsigned char *)s;
	while (n--)
		if (us[n] == (unsigned char)c)
			return ((void *)(us + n));
	return (NULL);
}
