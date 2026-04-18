/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:08:24 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/11 00:00:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "signal_handler.h"

void	exec_left_child(t_ast *node, t_shell_table *shell_table, int fd[2])
{
	int		status;
	t_ast	*left_node;
	t_ast	*right_node;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	set_signal_default();
	left_node = node->left;
	right_node = node->right;
	free(node);
	status = exec_ast(left_node, shell_table);
	free_ast(left_node);
	free_ast(right_node);
	exit(status);
}

void	exec_right_child(t_ast *node, t_shell_table *shell_table, int fd[2])
{
	int		status;
	t_ast	*left_node;
	t_ast	*right_node;

	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	close(fd[1]);
	close(fd[0]);
	set_signal_default();
	left_node = node->left;
	right_node = node->right;
	free(node);
	status = exec_ast(right_node, shell_table);
	free_ast(left_node);
	free_ast(right_node);
	exit(status);
}
