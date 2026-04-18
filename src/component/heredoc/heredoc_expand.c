/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/18 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

char	*heredoc_append_str(char *dst, const char *src)
{
	char	*result;

	if (!dst)
		return (ft_strdup(src));
	result = ft_strjoin(dst, src);
	free(dst);
	return (result);
}

static char	*expand_var(const char *s, size_t *i,
		t_shell_table *st)
{
	char	*key;
	char	*val;
	size_t	len;

	len = 0;
	while (s[*i + 1 + len]
		&& (ft_isalnum(s[*i + 1 + len]) || s[*i + 1 + len] == '_'))
		len++;
	if (len == 0)
		return (ft_strdup("$"));
	key = ft_substr(s, *i + 1, len);
	if (!key)
		return (NULL);
	*i += len;
	val = st_search(st, key);
	free(key);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

static char	*expand_dollar(const char *s, size_t *i,
		t_shell_table *st)
{
	char	*val;

	if (!s[*i + 1] || s[*i + 1] == ' ' || s[*i + 1] == '\n')
		return (ft_strdup("$"));
	if (s[*i + 1] == '?')
	{
		*i += 1;
		val = st_search(st, "?");
		if (!val)
			return (ft_strdup("0"));
		return (ft_strdup(val));
	}
	return (expand_var(s, i, st));
}

static char	*expand_one_char(char *result, const char *line,
		size_t *i, t_shell_table *st)
{
	char	*expanded;
	char	buf[2];

	if (line[*i] == '$')
	{
		expanded = expand_dollar(line, i, st);
		if (!expanded)
			return (free(result), NULL);
		result = heredoc_append_str(result, expanded);
		free(expanded);
	}
	else
	{
		buf[0] = line[*i];
		buf[1] = '\0';
		result = heredoc_append_str(result, buf);
	}
	return (result);
}

char	*expand_heredoc_line(const char *line, t_shell_table *st)
{
	char	*result;
	size_t	i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (line[i])
	{
		result = expand_one_char(result, line, &i, st);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
