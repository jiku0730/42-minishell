/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:08:24 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:22:17 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	fatal_child(int fd0, int fd1, int code)
{
	if (fd0 >= 0)
		close(fd0);
	if (fd1 >= 0)
		close(fd1);
	exit(code);
}

void	exec_left_child(t_ast *node, t_shell_table *shell_table, int fd[2])
{
	int		status;
	t_ast	*left_node;
	t_ast	*right_node;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
		fatal_child(fd[0], fd[1], 1);
	close(fd[0]);
	close(fd[1]);
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
		fatal_child(fd[0], fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	left_node = node->left;
	right_node = node->right;
	free(node);
	status = exec_ast(right_node, shell_table);
	free_ast(left_node);
	free_ast(right_node);
	exit(status);
}
