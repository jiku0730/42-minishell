/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:13:36 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "signal_handler.h"

static bool	is_heredoc_operator(const char *token);
static int	rebuild_tokens(t_list *current, t_list *eof_node,
				char *tmpfile_path);
static char	*strip_quotes(const char *s, bool *was_quoted);

static char	*process_heredoc(t_list *current, t_shell_table *st)
{
	t_list	*eof_node;
	bool	quoted;
	char	*delim;
	char	*tmpfile_path;

	eof_node = current->next;
	if (eof_node == NULL)
		return (NULL);
	delim = strip_quotes(eof_node->content, &quoted);
	if (!delim)
		return (NULL);
	tmpfile_path = heredoc_prompt(delim, !quoted, st);
	free(delim);
	if (!tmpfile_path)
		return (NULL);
	if (rebuild_tokens(current, eof_node, tmpfile_path) == ERROR)
		return (NULL);
	return (tmpfile_path);
}

t_list	*heredoc(t_list *tokens, t_shell_table *st)
{
	t_list	*current;

	current = tokens;
	while (current != NULL)
	{
		if (is_heredoc_operator((char *)current->content))
			if (!process_heredoc(current, st))
				return (NULL);
		current = current->next;
	}
	return (tokens);
}

static char	*strip_quotes(const char *s, bool *was_quoted)
{
	size_t	len;

	*was_quoted = false;
	len = ft_strlen(s);
	if (len >= 2 && ((s[0] == '\'' && s[len - 1] == '\'')
			|| (s[0] == '"' && s[len - 1] == '"')))
	{
		*was_quoted = true;
		return (ft_substr(s, 1, len - 2));
	}
	return (ft_strdup(s));
}

static bool	is_heredoc_operator(const char *token)
{
	if (token == NULL)
		return (false);
	return (ft_strncmp(token, "<<", 3) == 0);
}

static int	rebuild_tokens(t_list *current, t_list *eof_node,
		char *tmpfile_path)
{
	char	*input_redir;

	input_redir = ft_strdup("<");
	if (!current || !eof_node || !tmpfile_path || !input_redir)
		return (ERROR);
	free(current->content);
	free(eof_node->content);
	current->content = input_redir;
	eof_node->content = tmpfile_path;
	return (SUCCESS);
}
