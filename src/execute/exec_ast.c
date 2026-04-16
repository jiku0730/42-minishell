/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:10:34 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:07:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	exec_logical(t_ast *node, t_shell_table *shell_table)
{
	int	status;

	status = exec_ast(node->left, shell_table);
	if (node->type == AND && status == 0)
		return (exec_ast(node->right, shell_table));
	if (node->type == OR && status != 0)
		return (exec_ast(node->right, shell_table));
	return (status);
}

int	exec_ast(t_ast *node, t_shell_table *shell_table)
{
	if (!node)
		return (EXIT_FAILURE);
	if (node->type == PIPE)
		return (exec_pipe(node, shell_table));
	if (node->type == CMD)
		return (exec_cmd(node, shell_table));
	if (node->type == AND || node->type == OR)
		return (exec_logical(node, shell_table));
	return (EXIT_FAILURE);
}
