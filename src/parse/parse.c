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
		return (ERROR);
	*current = (*current)->next;
	if (!*current)
		return (ERROR);
	if (!add_redir_to_cmd(cmd, kind, (*current)->content))
		return (ERROR);
	return (SUCCESS);
}

static int	parse_token(t_list **current, t_cmd *cmd)
{
	if (is_redir(*current))
	{
		if (parse_redir(current, cmd) == ERROR)
			return (ERROR);
	}
	else if (is_word(*current))
	{
		if (!add_argv_to_cmd(cmd, (*current)->content))
			return (ERROR);
	}
	*current = (*current)->next;
	return (SUCCESS);
}

static bool	is_cmd_end(t_list *current)
{
	if (!current)
		return (true);
	return (is_symbol(current, "|") || is_symbol(current, "&&")
		|| is_symbol(current, "||") || is_symbol(current, ")"));
}

t_ast	*parse_cmd(t_list **current)
{
	t_ast	*ast;
	t_cmd	*cmd;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	while (!is_cmd_end(*current))
	{
		if (parse_token(current, cmd) == ERROR)
			return (free_cmd(cmd), NULL);
	}
	ast = new_ast_node(CMD);
	if (!ast)
		return (free_cmd(cmd), NULL);
	ast->cmd = cmd;
	return (ast);
}
