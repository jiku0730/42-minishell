/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:05:31 by urassh            #+#    #+#             */
/*   Updated: 2025/12/01 03:20:28 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include <readline/readline.h>

static int	write_line_to_file(int fd, char *line);
static char	*by_found_delimiter(char *line, int fd, char *tmpfile_path);
static void	*by_fail_write_line_to_file(char *line, int fd, char *tmpfile_path);

char	*heredoc_prompt(const char *delimiter)
{
	char	*line;
	char	*tmpfile_path;
	int		fd;

	tmpfile_path = create_tmpfile();
	if (tmpfile_path == NULL)
		return (NULL);
	fd = open_tmpfile(tmpfile_path);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = readline(HEREDOC_PROMPT);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
			return (by_found_delimiter(line, fd, tmpfile_path));
		if (write_line_to_file(fd, line) == ERROR)
			return (by_fail_write_line_to_file(line, fd, tmpfile_path));
		free(line);
	}
	close(fd);
	return (tmpfile_path);
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

static char	*by_found_delimiter(char *line, int fd, char *tmpfile_path)
{
	free(line);
	close(fd);
	return (tmpfile_path);
}

static void	*by_fail_write_line_to_file(char *line, int fd, char *tmpfile_path)
{
	free(line);
	close(fd);
	free(tmpfile_path);
	return (NULL);
}
