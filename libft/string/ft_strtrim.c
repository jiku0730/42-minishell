/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:58:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 15:00:04 by kjikuhar         ###   ########.fr       */
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
