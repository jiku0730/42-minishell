/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:10:34 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 16:25:41 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_ast(t_ast *node, char *const envp[])
{
	if (!node)
		return (EXIT_FAILURE);
	if (node->type == PIPE)
		return (exec_pipe(node, envp));
	else if (node->type == CMD)
		return (exec_cmd(node, envp));
	else
		return (EXIT_FAILURE);
}
