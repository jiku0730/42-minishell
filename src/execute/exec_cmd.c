/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:18:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/03/03 13:49:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static char	*join_path(const char *path, const char *cmd)
{
	size_t	path_len;
	size_t	cmd_len;
	char	*joined;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	joined = malloc(sizeof(char) * (path_len + 1 + cmd_len + 1));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, path, path_len + 1);
	joined[path_len] = '/';
	ft_strlcpy(joined + path_len + 1, cmd, cmd_len + 1);
	return (joined);
}

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

static char	*resolve_exec_path(const char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*find_exec_path(const char *cmd, t_shell_table *shell_table)
{
	char	*result;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		result = resolve_exec_path(cmd);
	else
		result = find_in_path(cmd, shell_table);
	return (result);
}

int	exec_cmd(t_ast *node, t_shell_table *shell_table)
{
	char	**argv;
	int		status;

	if (node->cmd->redirs)
	{
		if (exec_redirs(node->cmd->redirs) != 0)
			return (1);
	}
	status = exec_builtin_cmd(node, shell_table);
	if (status != -1)
		return (status);
	argv = list_to_argv(node->cmd->argv);
	if (!argv || !argv[0])
	{
		if (argv)
			ft_free_array((void **)argv);
		return (127);
	}
	return (exec_external_cmd(argv, shell_table));
}
