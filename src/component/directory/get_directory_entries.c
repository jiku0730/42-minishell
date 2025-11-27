/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory_entries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:30:40 by surayama          #+#    #+#             */
/*   Updated: 2025/11/27 16:08:26 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <directory.h>

static int	throw_error(void);

int	get_directory_entries(const char *path, bool include_hidden,
		t_list **entries)
{
	DIR				*dir;
	struct dirent	*entry;

	if (!entries)
		return (ERROR);
	*entries = NULL;
	dir = opendir(path);
	if (!dir)
		return (throw_error());
	while (true)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (!include_hidden && entry->d_name[0] == '.')
			continue ;
		ft_lstadd_back(entries, ft_lstnew(ft_strdup(entry->d_name)));
	}
	closedir(dir);
	return (SUCCESS);
}

static int	throw_error(void)
{
	if (errno == ENOENT)
		return (NOT_FOUND);
	else if (errno == EACCES)
		return (NO_PERMISSION);
	else if (errno == ENOTDIR)
		return (NOT_A_DIRECTORY);
	return (ERROR);
}
