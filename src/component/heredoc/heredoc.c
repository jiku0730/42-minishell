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

t_list	*heredoc(t_list *tokens)
{
	t_list	*current;
	t_list	*eof_node;
	char	*tmpfile_path;

	current = tokens;
	while (current != NULL)
	{
		if (is_heredoc_operator((char *)current->content))
		{
			eof_node = current->next;
			if (eof_node == NULL)
				return (NULL);
			set_signal_heredoc();
			tmpfile_path = heredoc_prompt((char *)eof_node->content);
			set_signal_interactive();
			if (tmpfile_path == NULL)
				return (NULL);
			if (rebuild_tokens(current, eof_node, tmpfile_path) == ERROR)
				return (NULL);
		}
		current = current->next;
	}
	return (tokens);
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
