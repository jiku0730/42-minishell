/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 05:46:56 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:19:25 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "signal_handler.h"

static int	exec_pipe_left(t_ast *node, t_shell_table *shell_table, \
				pid_t *left, int fd[2])
{
	*left = fork();
	if (*left == 0)
		exec_left_child(node, shell_table, fd);
	else if (*left < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	return (0);
}

static int	exec_pipe_right(t_ast *node, t_shell_table *shell_table, \
				pid_t *right, int fd[2])
{
	*right = fork();
	if (*right == 0)
		exec_right_child(node, shell_table, fd);
	else if (*right < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	return (0);
}

int	exec_pipe(t_ast *node, t_shell_table *shell_table)
{
	int		fd[2];
	pid_t	left;
	pid_t	right;
	int		exit_status_left_child;
	int		exit_status_right_child;

	if (pipe(fd) == -1)
		return (1);
	if (exec_pipe_left(node, shell_table, &left, fd) != 0)
		return (1);
	if (exec_pipe_right(node, shell_table, &right, fd) != 0)
	{
		if (left > 0)
			waitpid(left, NULL, 0);
		return (1);
	}
	close(fd[0]);
	close(fd[1]);
	set_signal_ignore();
	waitpid(left, &exit_status_left_child, 0);
	waitpid(right, &exit_status_right_child, 0);
	set_signal_interactive();
	if (ft_wifexited(exit_status_right_child))
		return (ft_wexitstatus(exit_status_right_child));
	return (128 + WTERMSIG(exit_status_right_child));
}
