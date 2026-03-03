/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:34:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/03/03 16:57:28 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

char	*join_path(const char *path_before, const char *path_after)
{
	size_t	path_len;
	size_t	cmd_len;
	char	*joined;

	path_len = ft_strlen(path_before);
	cmd_len = ft_strlen(path_after);
	joined = malloc(sizeof(char) * (path_len + 1 + cmd_len + 1));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, path_before, path_len + 1);
	joined[path_len] = '/';
	ft_strlcpy(joined + path_len + 1, path_after, cmd_len + 1);
	return (joined);
}
