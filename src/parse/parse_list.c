/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_ast_type	get_logical_type(t_list *current)
{
	if (is_symbol(current, "&&"))
		return (AND);
	if (is_symbol(current, "||"))
		return (OR);
	return (CMD);
}

t_ast	*parse_list(t_list **current)
{
	t_ast		*left;
	t_ast		*node;
	t_ast_type	type;

	left = parse_pipeline(current);
	if (!left)
		return (NULL);
	while (*current)
	{
		type = get_logical_type(*current);
		if (type != AND && type != OR)
			break ;
		*current = (*current)->next;
		node = new_ast_node(type);
		if (!node)
			return (free_ast(left), NULL);
		node->left = left;
		node->right = parse_pipeline(current);
		if (!node->right)
			return (free_ast(node), NULL);
		left = node;
	}
	return (left);
}

t_ast	*parse(t_list *token_head)
{
	t_list	*current;
	t_ast	*ast;

	current = token_head;
	ast = parse_list(&current);
	if (current != NULL)
	{
		free_ast(ast);
		return (NULL);
	}
	return (ast);
}
