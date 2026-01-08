/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 05:46:56 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:07:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_ast(t_ast *node, t_shell_table *shell_table);

int	exec_pipe_left(t_ast *node, char *const envp[], pid_t *left, int fd[2])
{
	*left = fork();
	if (*left == 0)
		exec_left_child(node, envp, fd);
	else if (*left < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	return (0);
}

int	exec_pipe_right(t_ast *node, char *const envp[], pid_t *right, int fd[2])
{
	*right = fork();
	if (*right == 0)
		exec_right_child(node, envp, fd);
	else if (*right < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	return (0);
}

int	exec_pipe(t_ast *node, char *const envp[])
{
	int		fd[2];
	pid_t	left;
	pid_t	right;
	int		exit_status_left_child;
	int		exit_status_right_child;

	if (pipe(fd) == -1)
		return (1);
	if (exec_pipe_left(node, envp, &left, fd) != 0)
		return (1);
	if (exec_pipe_right(node, envp, &right, fd) != 0)
	{
		if (left > 0)
			waitpid(left, NULL, 0);
		return (1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(left, &exit_status_left_child, 0);
	waitpid(right, &exit_status_right_child, 0);
	if (ft_wifexited(exit_status_right_child))
		return (ft_wexitstatus(exit_status_right_child));
	return (1);
}
