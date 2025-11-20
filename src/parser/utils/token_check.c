/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:29:48 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/19 23:39:47 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_word(const t_list *node)
{
	const char	*s;

	if (!node || !node->content)
		return (false);
	s = (const char *)node->content;
	if (ft_strncmp(s, "<", 2) == 0 || \
		ft_strncmp(s, ">", 2) == 0 || \
		ft_strncmp(s, ">>", 3) == 0 || \
		ft_strncmp(s, "|", 2) == 0 || \
		ft_strncmp(s, "EOF", 4) == 0)
		return (false);
	return (true);
}

bool	is_symbol(const t_list *node, const char *literal)
{
	size_t	len;

	if (!node || \
		!node->content || \
		!literal)
		return (false);
	len = ft_strlen(literal);
	return (ft_strncmp((const char *)node->content, literal, len + 1) == 0);
}

bool	is_eof(const t_list *node)
{
	if (!node || !node->content)
		return (true);
	return (ft_strncmp((const char *)node->content, "EOF", 4) == 0);
}

bool	is_redir(const t_list *node)
{
	if (!node)
		return (false);
	return (is_symbol(node, "<") || \
			is_symbol(node, ">") || \
			is_symbol(node, ">>"));
}

const char	*get_content(const t_list *node)
{
	if (!node)
		return (NULL);
	return ((const char *)node->content);
}
