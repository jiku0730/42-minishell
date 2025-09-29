/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:07:26 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/05 13:14:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_for_split_(char const *target_str, char delimiter)
{
	int	i;

	i = 0;
	while (target_str[i] != delimiter && target_str[i])
		i++;
	return (i);
}

static int	count_words_(char const *target_str, char delimiter)
{
	int	in_word_flag;
	int	count;

	in_word_flag = 0;
	count = 0;
	while (*target_str)
	{
		if (in_word_flag == 0)
		{
			if (*target_str == delimiter)
				in_word_flag = 0;
			else
			{
				in_word_flag = 1;
				count++;
			}
		}
		else if (in_word_flag == 1)
		{
			if (*target_str == delimiter)
				in_word_flag = 0;
		}
		target_str++;
	}
	return (count);
}

static char	*ft_strdup_for_split(char const **src, char delimiter)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen_for_split_(*src, delimiter) + 1);
	if (!dest)
		return (NULL);
	while (**src && **src != delimiter)
	{
		dest[i] = **src;
		i++;
		(*src)++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Helper function to free allocated strings in case of error */
static void	free_split_result(char **arr)
{
	char	**temp;

	if (!arr)
		return ;
	temp = arr;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	char	**p;

	splitted = malloc(sizeof(char *) * (count_words_(s, c) + 1));
	if (!splitted)
		return (NULL);
	p = splitted;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		*splitted = ft_strdup_for_split(&s, c);
		if (!*splitted)
			return (free_split_result(p), NULL);
		splitted++;
	}
	*splitted = NULL;
	return (p);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char *target_str = "//Hello/World /42/ Tok/yo!.../..";
// 	char delimiter = '/';
// 	int n = count_words_(target_str, delimiter);
// 	char	**strs = ft_split(target_str, delimiter);

// 	printf("%d\n", n);
// 	printf("%d\n", ft_strlen_for_split_(target_str, delimiter));
// 	for (int i = 0; i <= n; i++)
// 	{
// 		printf("[%d] : %s\n", i, strs[i]);
// 		free(strs[i]);
// 	}
// 	free(strs);
// 	return (0);
// }
