/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:29:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/19 23:39:17 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	add_redir_to_cmd(t_cmd *cmd, t_redir_kind kind, const char *file)
{
	t_redir	*redir;
	t_list	*node;

	redir = new_redir(kind, file);
	if (!redir)
		return (false);
	node = ft_lstnew(redir);
	if (!node)
	{
		free(redir->filename);
		free(redir);
		return (false);
	}
	ft_lstadd_back(&cmd->redirs, node);
	return (true);
}

bool	add_argv_to_cmd(t_cmd *cmd, const char *arg)
{
	char	*dup;
	t_list	*node;

	dup = ft_strdup(arg);
	if (!dup)
		return (false);
	node = ft_lstnew(dup);
	if (!node)
	{
		free(dup);
		return (false);
	}
	ft_lstadd_back(&cmd->argv, node);
	return (true);
}
