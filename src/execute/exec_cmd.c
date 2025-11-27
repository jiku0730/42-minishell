/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:18:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 16:39:17 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static char	*join_path(const char *s1, const char *s2, const char *s3)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s3_len;
	char	*s1_s2_s3;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	s1_s2_s3 = malloc(sizeof(char) * (s1_len + s2_len + s3_len + 1));
	if (!s1_s2_s3)
		return (NULL);
	ft_strlcpy(s1_s2_s3, s1, s1_len + 1);
	ft_strlcpy(s1_s2_s3 + s1_len, s2, s2_len + 1);
	ft_strlcpy(s1_s2_s3 + s1_len + s2_len, s3, s3_len + 1);
	return (s1_s2_s3);
}

static char	*find_in_path(const char *cmd, char *const envp[])
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;

	path_env = get_env_path(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], "/", cmd);
		if (!full_path)
			return (ft_free_split(paths), NULL);
		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

static char	*find_absolute_or_relative(const char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*find_command(const char *cmd, char *const envp[])
{
	char	*result;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		result = find_absolute_or_relative(cmd);
	else
		result = find_in_path(cmd, envp);
	return (result);
}

int	exec_cmd(t_ast *node, char *const envp[])
{
	char	**argv;

	if (node->cmd->redirs)
	{
		if (exec_redirs(node->cmd->redirs) != 0)
			return (1);
	}
	argv = list_to_argv(node->cmd->argv);
	if (!argv || !argv[0])
	{
		if (argv)
			ft_free_split(argv);
		return (127);
	}
	return (exec_cmd_core(argv, envp));
}
