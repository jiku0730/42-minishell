/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_question.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:21:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/16 22:37:34 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

static bool		has_question(const char *tok);
static size_t	count_question_len(const char *tok, size_t slen);
static char		*copy_and_advance(char *p, const char *status,
					size_t slen, const char **tok);
static char		*expand_question_token(const char *tok,
					const char *status, size_t slen);

static bool	has_question(const char *tok)
{
	char	quote;

	quote = 0;
	while (*tok)
	{
		if (!quote && ft_strchr("'\"", *tok))
			quote = *tok;
		else if (*tok == quote)
			quote = 0;
		else if (quote != '\'' && ft_strncmp(tok, "$?", 2) == 0)
			return (true);
		tok++;
	}
	return (false);
}

static size_t	count_question_len(const char *tok, size_t slen)
{
	size_t	len;
	char	quote;

	len = 0;
	quote = 0;
	while (*tok)
	{
		if (!quote && ft_strchr("'\"", *tok))
			quote = *tok;
		else if (*tok == quote)
			quote = 0;
		else if (quote != '\'' && ft_strncmp(tok, "$?", 2) == 0)
		{
			len += slen;
			tok++;
		}
		else
			len++;
		tok++;
	}
	return (len);
}

static char	*copy_and_advance(char *p, const char *status,
		size_t slen, const char **tok)
{
	ft_memcpy(p, status, slen);
	(*tok)++;
	return (p + slen);
}

static char	*expand_question_token(const char *tok,
		const char *status, size_t slen)
{
	char	*result;
	char	*p;
	char	quote;

	result = malloc(count_question_len(tok, slen) + 1);
	if (!result)
		return (NULL);
	p = result;
	quote = 0;
	while (*tok)
	{
		if (!quote && ft_strchr("'\"", *tok))
			quote = *tok;
		else if (*tok == quote)
			quote = 0;
		else if (quote != '\'' && ft_strncmp(tok, "$?", 2) == 0)
			p = copy_and_advance(p, status, slen, &tok);
		else
			*p++ = *tok;
		tok++;
	}
	*p = '\0';
	return (result);
}

t_list	*expand_question(t_list *tokens, int last_exit_status)
{
	char	*status;
	size_t	slen;
	t_list	*current;
	char	*expanded;

	status = ft_itoa(last_exit_status);
	if (!status)
		return (NULL);
	slen = ft_strlen(status);
	current = tokens;
	while (current)
	{
		if (current->content && has_question(current->content))
		{
			expanded = expand_question_token(current->content, status, slen);
			if (expanded)
			{
				free(current->content);
				current->content = expanded;
			}
		}
		current = current->next;
	}
	free(status);
	return (tokens);
}
