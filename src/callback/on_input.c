/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:25 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_input(char *input, t_shell_table *shell_table)
{
	t_list	*tokens;
	t_ast	*ast;

	tokens = tokenize(input);
	if (!tokens)
		return ;
	if (!heredoc(tokens))
	{
		ft_lstclear(&tokens, free);
		return ;
	}
	tokens = expand(tokens, shell_table);
	if (!tokens)
		return ;
	ast = parse(tokens);
	ft_lstclear(&tokens, free);
	if (!ast)
		return ;
	exec_ast(ast, shell_table);
	free_ast(ast);
}
