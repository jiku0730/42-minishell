/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "expand.h"

static void	expand_one_filename(t_redir *redir, t_shell_table *st)
{
	t_list	*tmp;
	char	*expanded;

	tmp = ft_lstnew(ft_strdup(redir->filename));
	if (!tmp)
		return ;
	tmp = expand(tmp, st);
	if (!tmp)
		return ;
	expanded = ft_strdup((char *)tmp->content);
	ft_lstclear(&tmp, free);
	if (!expanded)
		return ;
	free(redir->filename);
	redir->filename = expanded;
}

void	expand_redir_filenames(t_list *redirs, t_shell_table *st)
{
	t_redir	*redir;

	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		expand_one_filename(redir, st);
		redirs = redirs->next;
	}
}
