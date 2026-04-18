/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/18 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "parse.h"

static int	expand_redir_filename(t_redir *redir, t_shell_table *st)
{
	t_list	*tmp;
	char	*dup;

	dup = ft_strdup(redir->filename);
	if (!dup)
		return (ERROR);
	tmp = ft_lstnew(dup);
	if (!tmp)
		return (free(dup), ERROR);
	tmp = expand(tmp, st, st->last_status);
	if (!tmp)
		return (ERROR);
	free(redir->filename);
	redir->filename = ft_strdup(tmp->content);
	ft_lstclear(&tmp, free);
	if (!redir->filename)
		return (ERROR);
	return (SUCCESS);
}

static int	expand_redirs(t_list *redirs, t_shell_table *st)
{
	t_list	*current;

	current = redirs;
	while (current)
	{
		if (expand_redir_filename(current->content, st) == ERROR)
			return (ERROR);
		current = current->next;
	}
	return (SUCCESS);
}

int	expand_cmd(t_cmd *cmd, t_shell_table *shell_table)
{
	if (cmd->argv)
	{
		cmd->argv = expand(cmd->argv, shell_table,
				shell_table->last_status);
		if (!cmd->argv)
			return (ERROR);
	}
	if (cmd->redirs)
	{
		if (expand_redirs(cmd->redirs, shell_table) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
