/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:05:31 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 15:18:27 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_doc.h>
#include <readline/readline.h>

static char	*read_heredoc_lines(const char *delimiter);
static char	*append_line(char *content, char *line);

t_list	*here_doc_prompt(const char *delimiter)
{
	char	*content;
	t_list	*node;

	content = read_heredoc_lines(delimiter);
	if (content == NULL)
		return (NULL);
	node = ft_lstnew(content);
	if (node == NULL)
	{
		free(content);
		return (NULL);
	}
	return (node);
}

static char	*read_heredoc_lines(const char *delimiter)
{
	char	*line;
	char	*content;

	content = ft_strdup("");
	if (content == NULL)
		return (NULL);
	while (1)
	{
		line = readline(HEREDOC_PROMPT);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		content = append_line(content, line);
		free(line);
		if (content == NULL)
			return (NULL);
	}
	return (content);
}

static char	*append_line(char *content, char *line)
{
	char	*line_with_newline;
	char	*new_content;

	line_with_newline = ft_strjoin(line, "\n");
	if (line_with_newline == NULL)
	{
		free(content);
		return (NULL);
	}
	new_content = ft_strjoin(content, line_with_newline);
	free(content);
	free(line_with_newline);
	return (new_content);
}
