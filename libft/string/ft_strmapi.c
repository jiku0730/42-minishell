/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:57:28 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 14:59:45 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			s_length;
	char			*rtv_str;

	if (!s || !f)
		return (NULL);
	index = 0;
	s_length = ft_strlen(s);
	rtv_str = malloc(sizeof(char) * (s_length + 1));
	if (!rtv_str)
		return (NULL);
	while (s[index])
	{
		rtv_str[index] = (*f)(index, s[index]);
		index++;
	}
	rtv_str[index] = '\0';
	return (rtv_str);
}
