/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "path.h"

static char	*find_in_path(const char *cmd, t_shell_table *shell_table)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;

	path_env = st_search(shell_table, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (!full_path)
			return (ft_free_array((void **)paths), NULL);
		if (access(full_path, X_OK) == 0)
			return (ft_free_array((void **)paths), full_path);
		free(full_path);
		i++;
	}
	ft_free_array((void **)paths);
	return (NULL);
}

char	*find_exec_path(const char *cmd, t_shell_table *shell_table)
{
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (find_in_path(cmd, shell_table));
}
