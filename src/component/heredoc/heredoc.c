/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:13:36 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 15:52:41 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <heredoc.h>

static bool	is_heredoc_operator(const char *token);
static void	rebuild_tokens(t_list *current, t_list *eof_node,
				char *heredoc_content);

t_list	*heredoc(t_list *tokens)
{
	t_list	*current;
	t_list	*eof_node;
	char	*heredoc_content;

	current = tokens;
	while (current != NULL)
	{
		if (is_heredoc_operator((char *)current->content))
		{
			eof_node = current->next;
			if (eof_node == NULL)
				return (NULL);
			heredoc_content = heredoc_prompt((char *)eof_node->content);
			if (heredoc_content == NULL)
				return (NULL);
			rebuild_tokens(current, eof_node, heredoc_content);
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

static void	rebuild_tokens(t_list *current, t_list *eof_node,
		char *heredoc_content)
{
	free(current->content);
	current->content = heredoc_content;
	current->next = eof_node->next;
	free(eof_node->content);
	free(eof_node);
}
