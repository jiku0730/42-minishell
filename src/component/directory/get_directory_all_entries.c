/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory_all_entries.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:30:40 by surayama          #+#    #+#             */
/*   Updated: 2025/11/27 16:08:41 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <directory.h>

static int	throw_error(void);
static int	process_entry(const char *path, const char *name,
				bool include_hidden, t_list **entries);
static char	*join_path(const char *dir, const char *name);
static int	read_directory_entries(DIR *dir, const char *path,
				bool include_hidden, t_list **entries);

int	get_directory_all_entries(const char *path, bool include_hidden,
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
	result = get_directory_all_entries(full_path, include_hidden, &sub_entries);
	if (result == SUCCESS && sub_entries)
		ft_lstadd_back(entries, sub_entries);
	free(full_path);
	return (SUCCESS);
}

static char	*join_path(const char *dir, const char *name)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, name);
	free(temp);
	return (result);
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
