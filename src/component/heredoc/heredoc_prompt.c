/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:05:31 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "signal_handler.h"
#include <readline/readline.h>

static int	write_line(int fd, char *line, bool expand,
				t_shell_table *st);
static void	heredoc_child(const char *delim, int fd,
				bool expand, t_shell_table *st);

static int	wait_heredoc_child(pid_t pid)
{
	int	wstatus;

	waitpid(pid, &wstatus, 0);
	if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (-1);
	}
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (-1);
}

static void	*heredoc_interrupted(char *tmpfile_path)
{
	unlink(tmpfile_path);
	free(tmpfile_path);
	set_signal_interactive();
	g_signal = SIGINT;
	return (NULL);
}

char	*heredoc_prompt(const char *delim, bool expand,
		t_shell_table *st)
{
	char	*tmpfile_path;
	int		fd;
	pid_t	pid;

	tmpfile_path = create_tmpfile();
	if (tmpfile_path == NULL)
		return (NULL);
	fd = open_tmpfile(tmpfile_path);
	if (fd == -1)
		return (free(tmpfile_path), NULL);
	pid = fork();
	if (pid == 0)
	{
		set_signal_default();
		heredoc_child(delim, fd, expand, st);
	}
	close(fd);
	set_signal_ignore();
	if (wait_heredoc_child(pid) != 0)
		return (heredoc_interrupted(tmpfile_path));
	set_signal_interactive();
	return (tmpfile_path);
}

static void	heredoc_child(const char *delim, int fd,
		bool expand, t_shell_table *st)
{
	char	*line;
	int		status;

	status = 0;
	while (1)
	{
		line = readline(HEREDOC_PROMPT);
		if (!line || ft_strncmp(line, delim,
				ft_strlen(delim) + 1) == 0)
			break ;
		if (write_line(fd, line, expand, st) == ERROR)
		{
			status = 1;
			break ;
		}
		free(line);
	}
	free(line);
	exit(status);
}

static int	write_line(int fd, char *line, bool expand,
		t_shell_table *st)
{
	char	*out;

	if (expand)
		out = expand_heredoc_line(line, st);
	else
		out = line;
	if (!out)
		return (ERROR);
	if (write(fd, out, ft_strlen(out)) == -1
		|| write(fd, "\n", 1) == -1)
	{
		if (expand)
			free(out);
		return (ERROR);
	}
	if (expand)
		free(out);
	return (SUCCESS);
}
