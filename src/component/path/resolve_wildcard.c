/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_wildcard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 13:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "pattern.h"
#include "directory.h"

static t_list	*get_matches(const char *abs_dir, const char *pattern);
static t_list	*build_full_paths(t_list *matches, const char *abs_dir);

t_list	*resolve_wildcard(const char *token)
{
	char	*slash;
	char	*dir;
	char	*abs_dir;
	t_list	*result;

	slash = ft_strrchr(token, '/');
	if (slash)
		dir = ft_substr(token, 0, slash - token + 1);
	else
		dir = ft_strdup(".");
	abs_dir = to_absolute_path(dir);
	free(dir);
	if (!abs_dir)
		return (NULL);
	if (slash)
		result = get_matches(abs_dir, slash + 1);
	else
		result = get_matches(abs_dir, token);
	free(abs_dir);
	return (result);
}

static t_list	*get_matches(const char *abs_dir, const char *pattern)
{
	t_list	*entries;
	t_list	*matches;
	t_list	*result;

	if (get_directory_entries(abs_dir, pattern[0] == '.', &entries) != SUCCESS)
		return (NULL);
	matches = filter_pattern(entries, pattern);
	ft_lstclear(&entries, free);
	result = build_full_paths(matches, abs_dir);
	ft_lstclear(&matches, free);
	return (result);
}

static t_list	*build_full_paths(t_list *matches, const char *abs_dir)
{
	t_list	*result;
	t_list	*current;
	t_list	*node;
	char	*dir_slash;
	char	*full_path;

	result = NULL;
	dir_slash = ft_strjoin(abs_dir, "/");
	if (!dir_slash)
		return (NULL);
	current = matches;
	while (current)
	{
		full_path = ft_strjoin(dir_slash, (char *)current->content);
		node = ft_lstnew(full_path);
		if (!node)
		{
			free(full_path);
			break ;
		}
		ft_lstadd_back(&result, node);
		current = current->next;
	}
	free(dir_slash);
	return (result);
}
