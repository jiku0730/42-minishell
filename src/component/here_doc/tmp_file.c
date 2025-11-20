/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:49 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 14:52:28 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_doc.h>

static char	*get_tmpfile_id(const char *tmp_prefix);

int	open_tmpfile(void)
{
	const char	*tmp_prefix = "/tmp/minishell_heredoc_";
	char		*id;
	char		*path;
	int			tmp_file_id;

	id = get_tmpfile_id(tmp_prefix);
	if (id == NULL)
		return (-1);
	path = ft_strjoin(tmp_prefix, id);
	if (path == NULL)
	{
		free(id);
		return (-1);
	}
	tmp_file_id = open(path, O_CREAT | O_EXCL | O_RDWR, 0600);
	free(id);
	free(path);
	return (tmp_file_id);
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
