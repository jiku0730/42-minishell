/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:57:42 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/20 11:49:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_pipe_node(t_ast *node, const char *prefix, bool is_last)
{
	char	child_prefix[256];

	print_branch_line(prefix, is_last, "PIPE");
	build_child_prefix(prefix, is_last, child_prefix, sizeof(child_prefix));
	print_pipe_children(node, child_prefix);
}

void	print_cmd_node(t_ast *node, const char *prefix, bool is_last)
{
	char	child_prefix[256];
	t_list	*argv_list;
	t_list	*redir_list;

	argv_list = NULL;
	redir_list = NULL;
	if (node->cmd)
	{
		argv_list = node->cmd->argv;
		redir_list = node->cmd->redirs;
	}
	print_branch_line(prefix, is_last, "CMD");
	build_child_prefix(prefix, is_last, child_prefix, sizeof(child_prefix));
	print_argv_line(child_prefix, false, argv_list);
	print_redir_line(child_prefix, true, redir_list);
}

void	print_ast_node(t_ast *node, const char *prefix, bool is_last)
{
	if (!node)
	{
		print_branch_line(prefix, is_last, "(null)");
		return ;
	}
	if (node->type == PIPE)
	{
		print_pipe_node(node, prefix, is_last);
		return ;
	}
	if (node->type == CMD)
	{
		print_cmd_node(node, prefix, is_last);
		return ;
	}
	return ;
}

void	print_ast(t_ast *ast_root)
{
	printf("AST\n");
	print_ast_node(ast_root, "", true);
}
