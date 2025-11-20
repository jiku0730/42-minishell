/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:30:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/19 23:51:59 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_redir(t_list **cursor, t_cmd *cmd)
{
	if (is_symbol(*cursor, "<"))
	{
		*cursor = (*cursor)->next;
		if (!*cursor || !add_redir_to_cmd(cmd, R_IN, get_content(*cursor)))
			return (false);
	}
	else if (is_symbol(*cursor, ">"))
	{
		*cursor = (*cursor)->next;
		if (!*cursor)
			return (false);
		if (!add_redir_to_cmd(cmd, R_OUT_TRUNC, get_content(*cursor)))
			return (false);
	}
	else if (is_symbol(*cursor, ">>"))
	{
		*cursor = (*cursor)->next;
		if (!*cursor)
			return (false);
		if (!add_redir_to_cmd(cmd, R_OUT_APPEND, get_content(*cursor)))
			return (false);
	}
	else
		return (false);
	return (true);
}

static t_ast	*parse_cmd(t_list **cursor)
{
	t_ast	*ast;
	t_cmd	*cmd;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	while (*cursor && !is_symbol(*cursor, "|") && !is_eof(*cursor))
	{
		if (is_redir(*cursor))
		{
			if (!parse_redir(cursor, cmd))
				return (free_cmd(cmd), NULL);
		}
		else if (is_word(*cursor))
		{
			if (!add_argv_to_cmd(cmd, get_content(*cursor)))
				return (free_cmd(cmd), NULL);
		}
		*cursor = (*cursor)->next;
	}
	ast = new_ast_node(CMD);
	if (!ast)
		return (free_cmd(cmd), NULL);
	ast->cmd = cmd;
	return (ast);
}

static t_ast	*parse_pipeline(t_list **cursor)
{
	t_ast	*left;
	t_ast	*pipe_node;

	left = parse_cmd(cursor);
	if (!left)
		return (NULL);
	if (*cursor && is_symbol(*cursor, "|"))
	{
		*cursor = (*cursor)->next;
		pipe_node = new_ast_node(PIPE);
		if (!pipe_node)
			return (free_ast(left), NULL);
		pipe_node->left = left;
		pipe_node->right = parse_pipeline(cursor);
		if (!pipe_node->right)
			return (free_ast(pipe_node), NULL);
		return (pipe_node);
	}
	return (left);
}

t_ast	*parser(t_list *head)
{
	t_list	*cursor;
	t_ast	*root;

	cursor = head;
	root = parse_pipeline(&cursor);
	return (root);
}
