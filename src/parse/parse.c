/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:30:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 11:55:22 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static t_redir_kind	find_redir_kind(t_list *current)
{
	if (is_symbol(current, "<"))
		return (R_IN);
	else if (is_symbol(current, ">"))
		return (R_OUT_TRUNC);
	else if (is_symbol(current, ">>"))
		return (R_OUT_APPEND);
	else
		return (R_NOT_FOUND);
}

static int	parse_redir(t_list **current, t_cmd *cmd)
{
	t_redir_kind	kind;

	kind = find_redir_kind(*current);
	if (kind == R_NOT_FOUND)
		return (0);
	*current = (*current)->next;
	if (!*current || !is_word(*current))
		return (0);
	if (!add_redir_to_cmd(cmd, kind, (*current)->content))
		return (0);
	return (1);
}

static t_ast	*wrap_cmd(t_cmd *cmd)
{
	t_ast	*ast;

	if (!cmd->argv && !cmd->redirs)
		return (free_cmd(cmd), NULL);
	ast = new_ast_node(CMD);
	if (!ast)
		return (free_cmd(cmd), NULL);
	ast->cmd = cmd;
	return (ast);
}

static t_ast	*parse_cmd(t_list **current)
{
	t_cmd	*cmd;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	while (*current && !is_symbol(*current, "|")
		&& !is_symbol(*current, "&&")
		&& !is_symbol(*current, "||"))
	{
		if (is_redir(*current))
		{
			if (!parse_redir(current, cmd))
				return (free_cmd(cmd), NULL);
		}
		else if (is_word(*current))
		{
			if (!add_argv_to_cmd(cmd, (*current)->content))
				return (free_cmd(cmd), NULL);
		}
		else
			return (free_cmd(cmd), NULL);
		*current = (*current)->next;
	}
	return (wrap_cmd(cmd));
}

t_ast	*parse_pipeline(t_list **current)
{
	t_ast	*left;
	t_ast	*pipe_node;

	left = parse_cmd(current);
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
