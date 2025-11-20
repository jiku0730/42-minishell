/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:13:36 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 15:05:40 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_doc.h>

static bool	is_heredoc_operator(const char *token);
static void rebuild_tokens_with_heredoc(t_list *current, t_list *heredoc_node, t_list *eof_node);

t_list	*here_doc(t_list *tokens)
{
	t_list	*current;
	t_list	*eof_node;
	t_list	*heredoc_node;

	current = tokens;
	while (current != NULL)
	{
		if (is_heredoc_operator((char *)current->content))
		{
			eof_node = current->next;
			if (eof_node == NULL)
				return (NULL);
			heredoc_node = here_doc_prompt((char *)eof_node->content);
			if (heredoc_node == NULL)
				return (NULL);
            rebuild_tokens_with_heredoc(current, heredoc_node, eof_node);
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

static void rebuild_tokens_with_heredoc(t_list *current, t_list *heredoc_node, t_list *eof_node)
{
    current->content = heredoc_node->content;
    current->next = eof_node->next;
    free(eof_node->content);
    free(eof_node);
    free(heredoc_node);
}
