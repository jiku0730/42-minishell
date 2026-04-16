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

static int	write_line_to_file(int fd, char *line);
static void	heredoc_child(const char *delimiter, int fd);

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

char	*heredoc_prompt(const char *delimiter)
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
		heredoc_child(delimiter, fd);
	}
	close(fd);
	set_signal_ignore();
	if (wait_heredoc_child(pid) != 0)
		return (heredoc_interrupted(tmpfile_path));
	set_signal_interactive();
	return (tmpfile_path);
}

static void	heredoc_child(const char *delimiter, int fd)
{
	char	*line;
	int		status;

	status = 0;
	while (1)
	{
		line = readline(HEREDOC_PROMPT);
		if (!line || ft_strncmp(line, delimiter,
				ft_strlen(delimiter) + 1) == 0)
			break ;
		if (write_line_to_file(fd, line) == ERROR)
		{
			status = 1;
			break ;
		}
		free(line);
	}
	free(line);
	exit(status);
}

static int	write_line_to_file(int fd, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (write(fd, line, len) == -1)
		return (ERROR);
	if (write(fd, "\n", 1) == -1)
		return (ERROR);
	return (SUCCESS);
}
