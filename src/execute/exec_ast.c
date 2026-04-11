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

int	exec_ast(t_ast *node, t_shell_table *shell_table)
{
	if (!node)
		return (EXIT_FAILURE);
	if (node->type == PIPE)
		return (exec_pipe(node, shell_table));
	else if (node->type == CMD)
		return (exec_cmd(node, shell_table));
	else
		return (EXIT_FAILURE);
}
