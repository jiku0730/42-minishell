/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:14:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 11:36:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp ;
	char	*p;

	tmp = (char *)malloc(sizeof(s[0]) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	p = tmp;
	while (*s)
	{
		*tmp = *s;
		s++;
		tmp++;
	}
	*tmp = '\0';
	return (p);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*c;
// 	char	*d;

// 	c = "1234567890";
// 	d = ft_strdup(c);
// 	printf("%s", ft_strdup(c));
// 	free(d);
// 	return (0);
// }
