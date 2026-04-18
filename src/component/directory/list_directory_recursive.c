/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_directory_recursive.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:30:40 by surayama          #+#    #+#             */
/*   Updated: 2025/12/01 03:20:12 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directory.h"
#include "path.h"

static int	throw_error(void);
static int	process_entry(const char *path, const char *name,
				bool include_hidden, t_list **entries);
static int	read_directory_entries(DIR *dir, const char *path,
				bool include_hidden, t_list **entries);

int	list_directory_recursive(const char *path, bool include_hidden,
		t_list **entries)
{
	DIR	*dir;
	int	result;

	if (!entries)
		return (ERROR);
	*entries = NULL;
	dir = opendir(path);
	if (!dir)
		return (throw_error());
	result = read_directory_entries(dir, path, include_hidden, entries);
	closedir(dir);
	return (result);
}

static int	read_directory_entries(DIR *dir, const char *path,
		bool include_hidden, t_list **entries)
{
	struct dirent	*entry;
	int				result;

	while (true)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (!include_hidden && entry->d_name[0] == '.')
			continue ;
		result = process_entry(path, entry->d_name, include_hidden, entries);
		if (result != SUCCESS)
			return (result);
	}
	return (SUCCESS);
}

static int	process_entry(const char *path, const char *name,
		bool include_hidden, t_list **entries)
{
	char		*full_path;
	struct stat	st;
	t_list		*sub_entries;
	int			result;

	full_path = join_path(path, name);
	if (!full_path)
		return (ERROR);
	ft_lstadd_back(entries, ft_lstnew(ft_strdup(full_path)));
	if (stat(full_path, &st) != 0 || !S_ISDIR(st.st_mode))
	{
		free(full_path);
		return (SUCCESS);
	}
	if (ft_strncmp(name, ".", 2) == 0 || ft_strncmp(name, "..", 3) == 0)
	{
		free(full_path);
		return (SUCCESS);
	}
	result = list_directory_recursive(full_path, include_hidden, &sub_entries);
	if (result == SUCCESS && sub_entries)
		ft_lstadd_back(entries, sub_entries);
	free(full_path);
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
