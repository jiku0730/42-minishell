/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmpfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:49 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 17:36:29 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <heredoc.h>

static char	*get_tmpfile_id(const char *tmp_prefix);

int	open_tmpfile(char *tmpfile_path)
{
	int	fd;

	fd = open(tmpfile_path, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		free(tmpfile_path);
		*tmpfile_path = NULL;
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
	if (path == NULL)
	{
		free(id);
		return (NULL);
	}
	tmp_file_id = open(path, O_CREAT | O_EXCL | O_RDWR, 0600);
	free(id);
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
		filename = ft_strjoin(tmp_prefix, id_str);
		free(id_str);
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
