/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:38:13 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/19 23:52:47 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	free_redir(void *ptr)
{
	t_redir	*redir;

	redir = (t_redir *)ptr;
	if (!redir)
		return ;
	if (redir->filename)
		free(redir->filename);
	free(redir);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	ft_lstclear(&cmd->argv, free);
	ft_lstclear(&cmd->redirs, free_redir);
	free(cmd);
}

void	free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == CMD)
		free_cmd(ast->cmd);
	else
	{
		free_ast(ast->left);
		free_ast(ast->right);
	}
	free(ast);
}
