/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmpfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:49 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*get_tmpfile_id(const char *tmp_prefix);

int	open_tmpfile(char *tmpfile_path)
{
	int	fd;

	fd = open(tmpfile_path, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		free(tmpfile_path);
		tmpfile_path = NULL;
		return (-1);
	}
	return (fd);
}

char	*create_tmpfile(void)
{
	char	*id;
	char	*path;
	int		tmp_file_id;

	id = get_tmpfile_id(HEREDOC_TMP_PREFIX);
	if (id == NULL)
		return (NULL);
	path = ft_strjoin(HEREDOC_TMP_PREFIX, id);
	free(id);
	if (path == NULL)
		return (NULL);
	tmp_file_id = open(path, O_CREAT | O_EXCL | O_RDWR, 0600);
	if (tmp_file_id == -1)
		return (NULL);
	close(tmp_file_id);
	return (path);
}

static char	*get_tmpfile_id(const char *tmp_prefix)
{
	int		id;
	char	*filename;
	char	*id_str;

	id = 0;
	while (id < INT_MAX)
	{
		id_str = ft_itoa(id);
		if (!id_str)
			return (NULL);
		filename = ft_strjoin(tmp_prefix, id_str);
		free(id_str);
		if (!filename)
			return (NULL);
		if (access(filename, F_OK) != 0)
		{
			free(filename);
			return (ft_itoa(id));
		}
		free(filename);
		id++;
	}
	return (NULL);
}
