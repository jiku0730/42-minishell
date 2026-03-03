/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static t_list	*split_cdpath(const char *cdpath);
static char		*try_cdpath_entry(const char *entry, const char *arg);

char	*search_cdpath(const char *arg, t_shell_table *st)
{
	char	*cdpath;
	t_list	*entries;
	t_list	*cur;
	char	*result;

	cdpath = st_search(st, "CDPATH");
	if (!cdpath)
		return (NULL);
	entries = split_cdpath(cdpath);
	cur = entries;
	while (cur)
	{
		result = try_cdpath_entry((char *)cur->content, arg);
		if (result)
		{
			ft_lstclear(&entries, free);
			return (result);
		}
		cur = cur->next;
	}
	ft_lstclear(&entries, free);
	return (NULL);
}

static char	*try_cdpath_entry(const char *entry, const char *arg)
{
	char	*joined;
	char	*absolute;

	joined = join_path(entry, arg);
	if (!joined)
		return (NULL);
	absolute = to_absolute_path(joined);
	free(joined);
	if (!absolute)
		return (NULL);
	if (access(absolute, F_OK) == 0)
		return (absolute);
	free(absolute);
	return (NULL);
}

static void	add_entry(t_list **list, const char *cdpath, size_t start,
		size_t end)
{
	char	*entry;

	if (start == end)
		entry = ft_strdup(".");
	else
		entry = ft_substr(cdpath, start, end - start);
	if (entry)
		ft_lstadd_back(list, ft_lstnew(entry));
}

static t_list	*split_cdpath(const char *cdpath)
{
	t_list	*list;
	size_t	i;
	size_t	start;

	list = NULL;
	i = 0;
	start = 0;
	while (cdpath[i])
	{
		if (cdpath[i] == ':')
		{
			add_entry(&list, cdpath, start, i);
			start = i + 1;
		}
		i++;
	}
	add_entry(&list, cdpath, start, i);
	return (list);
}
