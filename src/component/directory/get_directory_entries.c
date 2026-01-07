/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory_entries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:30:40 by surayama          #+#    #+#             */
/*   Updated: 2025/12/01 03:20:12 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directory.h"

static int	throw_error(void);
static int	append_entry(t_list **entries, const char *entry_name);

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
		if (append_entry(entries, entry->d_name) == ERROR)
		{
			closedir(dir);
			return (ERROR);
		}
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

static int	append_entry(t_list **entries, const char *entry_name)
{
	t_list	*entry_node;

	entry_node = ft_lstnew(ft_strdup(entry_name));
	if (!entry_node)
		return (ERROR);
	ft_lstadd_back(entries, entry_node);
	return (SUCCESS);
}
