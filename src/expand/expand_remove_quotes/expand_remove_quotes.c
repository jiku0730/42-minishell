/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:51:36 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include <stdlib.h>

static int	count_unquoted_len(const char *str);
static char	*remove_quotes_from_string(const char *str);

t_list	*expand_remove_quotes(t_list *tokens)
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

static int	count_unquoted_len(const char *str)
{
	int		len;
	char	quote;

	len = 0;
	quote = 0;
	while (*str)
	{
		if (!quote && (*str == '\'' || *str == '"'))
			quote = *str;
		else if (*str == quote)
			quote = 0;
		else
			len++;
		str++;
	}
	return (len);
}

static char	*remove_quotes_from_string(const char *str)
{
	char	*result;
	char	quote;
	int		j;

	result = malloc(sizeof(char) * (count_unquoted_len(str) + 1));
	if (!result)
		return (NULL);
	quote = 0;
	j = 0;
	while (*str)
	{
		if (!quote && (*str == '\'' || *str == '"'))
			quote = *str;
		else if (*str == quote)
			quote = 0;
		else
			result[j++] = *str;
		str++;
	}
	result[j] = '\0';
	return (result);
}
