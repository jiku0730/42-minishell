/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:51:36 by surayama          #+#    #+#             */
/*   Updated: 2026/02/13 23:26:09 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "remove_quotes.h"
#include <stdlib.h>

static bool	is_quote(char c);
static char	*remove_quotes_from_string(const char *str);
static int	removed_str_length(const char *str);

t_list	*remove_quotes(t_list *tokens)
{
	t_list	*current;
	char	*new_content;
	char	*old_content;

	if (!tokens)
		return (NULL);
	current = tokens;
	while (current)
	{
		if (current->content)
		{
			new_content = remove_quotes_from_string((char *)current->content);
			if (!new_content)
				return (NULL);
			old_content = current->content;
			current->content = new_content;
			free(old_content);
		}
		current = current->next;
	}
	return (tokens);
}

static int	removed_str_length(const char *str)
{
	size_t	len;
	size_t	quote_count;

	len = ft_strlen(str);
	quote_count = 0;
	while (*str)
	{
		if (is_quote(*str))
			quote_count++;
		str++;
	}
	return (len - quote_count);
}

static char	*remove_quotes_from_string(const char *str)
{
	char	*removed_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	removed_str = malloc(sizeof(char) * (removed_str_length(str) + 1));
	if (!removed_str)
		return (NULL);
	while (str[i])
	{
		if (!is_quote(str[i]))
		{
			removed_str[j] = str[i];
			j++;
		}
		i++;
	}
	removed_str[j] = '\0';
	return (removed_str);
}

static bool	is_quote(char c)
{
	return (c == '\'' || c == '"' || c == '`');
}
