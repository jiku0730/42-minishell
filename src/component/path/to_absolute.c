/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_absolute_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

static t_list	*init_resolved_path(bool is_head_absolute, t_list **path_list);
static t_list	*split_path_to_list(const char *path);
static void		consume_head(t_list **path_list);
static char		*list_to_path(t_list *resolved_path);

char	*to_absolute_path(const char *path)
{
	t_list	*path_list;
	t_list	*resolved_path;
	t_list	*current;
	char	*result;

	if (!path || !*path)
		return (NULL);
	if (ft_strncmp(path, "/", 2) == 0)
		return (ft_strdup("/"));
	path_list = split_path_to_list(path);
	if (!path_list && path[0] == '/')
		return (ft_strdup("/"));
	resolved_path = init_resolved_path(path[0] == '/', &path_list);
	current = path_list;
	while (current)
	{
		resolved_path = append_path(&resolved_path, (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&path_list, free);
	result = list_to_path(resolved_path);
	ft_lstclear(&resolved_path, free);
	return (result);
}

static t_list	*init_resolved_path(bool is_head_absolute, t_list **path_list)
{
	char	*cwd;
	t_list	*resolved_path;

	resolved_path = NULL;
	if (is_head_absolute)
	{
		while (*path_list)
		{
			if (ft_strncmp((char *)(*path_list)->content, ".", 2) == 0
				|| ft_strncmp((char *)(*path_list)->content, "..", 3) == 0)
				break ;
			if (!append_path(&resolved_path, (char *)(*path_list)->content))
				return (NULL);
			consume_head(path_list);
		}
		return (resolved_path);
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	resolved_path = split_path_to_list(cwd);
	free(cwd);
	return (resolved_path);
}

static void	consume_head(t_list **path_list)
{
	t_list	*temp;

	temp = *path_list;
	*path_list = (*path_list)->next;
	ft_lstdelone(temp, free);
}

static t_list	*split_path_to_list(const char *path)
{
	char	**segments;
	t_list	*list;
	int		i;

	if (!path)
		return (NULL);
	segments = ft_split(path, '/');
	if (!segments)
		return (NULL);
	list = NULL;
	i = 0;
	while (segments[i])
	{
		ft_lstadd_back(&list, ft_lstnew(segments[i]));
		i++;
	}
	free(segments);
	return (list);
}

static char	*list_to_path(t_list *resolved_path)
{
	t_list	*current;
	char	*result;
	char	*temp;

	if (!resolved_path)
		return (ft_strdup("/"));
	result = ft_strdup("/");
	current = resolved_path;
	while (current)
	{
		temp = ft_strjoin(result, (char *)current->content);
		if (result)
			free(result);
		if (!temp)
			return (NULL);
		result = temp;
		if (current->next)
		{
			temp = ft_strjoin(result, "/");
			free(result);
			result = temp;
		}
		current = current->next;
	}
	return (result);
}
