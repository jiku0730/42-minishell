/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:41:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 16:45:26 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	exec_redir_in(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror(filename);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	exec_redir_out_trunc(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(filename);
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror(filename);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	exec_redir_out_append(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(filename);
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror(filename);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	exec_one_redir(t_redir *redir)
{
	if (redir->kind == R_IN)
	{
		if (exec_redir_in(redir->filename) != 0)
			return (ERROR);
	}
	else if (redir->kind == R_OUT_TRUNC)
	{
		if (exec_redir_out_trunc(redir->filename) != 0)
			return (ERROR);
	}
	else if (redir->kind == R_OUT_APPEND)
	{
		if (exec_redir_out_append(redir->filename) != 0)
			return (ERROR);
	}
	return (SUCCESS);
}

int	exec_redirs(t_list *redirs)
{
	t_list	*current;
	t_redir	*redir;

	current = redirs;
	while (current)
	{
		redir = (t_redir *)current->content;
		if (exec_one_redir(redir) != 0)
			return (1);
		current = current->next;
	}
	return (0);
}
