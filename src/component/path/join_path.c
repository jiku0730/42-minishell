/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:34:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/03/03 16:44:45 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

char	*join_path(const char *path, const char *cmd)
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
