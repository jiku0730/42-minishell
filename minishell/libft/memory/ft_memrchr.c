/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:16:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/05 20:02:01 by kjikuhar         ###   ########.fr       */
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

// #include <assert.h>
// #include <stddef.h>
// #include <string.h>

// static void	test_ft_memrchr_a_found(void)
// {
// 	const char	s[] = "abcabc";

// 	assert(ft_memrchr(s, 'a', 6) == s + 3);
// }

// static void	test_ft_memrchr_c_found(void)
// {
// 	const char	s[] = "abcabc";

// 	assert(ft_memrchr(s, 'c', 6) == s + 5);
// }

// static void	test_ft_memrchr_n_zero(void)
// {
// 	const char	s[] = "abcabc";

// 	assert(ft_memrchr(s, 'a', 0) == NULL);
// }

// static void	test_ft_memrchr_tail_only(void)
// {
// 	const char	s[] = "abcabc";

// 	assert(ft_memrchr(s + 5, 'c', 1) == s + 5);
// }

// static void	test_ft_memrchr_not_found(void)
// {
// 	const char	s[] = "abcabc";

// 	assert(ft_memrchr(s, 'x', 6) == NULL);
// }

// static void	test_ft_memrchr_binary(void)
// {
// 	const unsigned char	s[] = {0x00, 0xff, 0x00, 0xff};

// 	assert(ft_memrchr(s, 0xff, 4) == s + 3);
// }

// int	main(void)
// {
// 	test_ft_memrchr_a_found();
// 	test_ft_memrchr_c_found();
// 	test_ft_memrchr_n_zero();
// 	test_ft_memrchr_tail_only();
// 	test_ft_memrchr_not_found();
// 	test_ft_memrchr_binary();
// 	return (0);
// }
