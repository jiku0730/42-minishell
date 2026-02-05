/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:29:48 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/02/05 16:28:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_word(const t_list *node)
{
	const char	*s;

	if (!node || !node->content)
		return (false);
	s = (const char *)node->content;
	if (ft_strncmp(s, "<", 2) == 0 || ft_strncmp(s, ">", 2) == 0
		|| ft_strncmp(s, ">>", 3) == 0 || ft_strncmp(s, "|", 2) == 0
		|| ft_strncmp(s, "EOF", 4) == 0)
		return (false);
	return (true);
}

bool	is_symbol(const t_list *node, const char *literal)
{
	size_t	len;

	if (!node || !node->content || !literal)
		return (false);
	len = ft_strlen(literal);
	return (ft_strncmp((const char *)node->content, literal, len + 1) == 0);
}

bool	is_redir(const t_list *node)
{
	if (!node)
		return (false);
	return (is_symbol(node, "<") || is_symbol(node, ">") || is_symbol(node,
			">>"));
}
