/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_ast	*parse_subshell(t_list **current)
{
	t_ast	*node;

	*current = (*current)->next;
	node = new_ast_node(SUBSHELL);
	if (!node)
		return (NULL);
	node->right = parse_list(current);
	if (!node->right)
		return (free_ast(node), NULL);
	if (!*current || !is_symbol(*current, ")"))
		return (free_ast(node), NULL);
	*current = (*current)->next;
	return (node);
}

static t_ast	*parse_primary(t_list **current)
{
	if (*current && is_symbol(*current, "("))
		return (parse_subshell(current));
	return (parse_cmd(current));
}

t_ast	*parse_pipeline(t_list **current)
{
	t_ast	*left;
	t_ast	*pipe_node;

	left = parse_primary(current);
	if (!left)
		return (NULL);
	if (*current && is_symbol(*current, "|"))
	{
		*current = (*current)->next;
		pipe_node = new_ast_node(PIPE);
		if (!pipe_node)
			return (free_ast(left), NULL);
		pipe_node->left = left;
		pipe_node->right = parse_pipeline(current);
		if (!pipe_node->right)
			return (free_ast(pipe_node), NULL);
		return (pipe_node);
	}
	return (left);
}
