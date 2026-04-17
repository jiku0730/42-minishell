/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:25 by surayama          #+#    #+#             */
/*   Updated: 2026/04/17 21:23:20 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	on_input(char *input, t_shell_table *shell_table, int last_status)
{
	t_list	*tokens;
	t_ast	*ast;

	tokens = tokenize(input);
	if (!tokens)
		return (2);
	if (!heredoc(tokens))
	{
		ft_lstclear(&tokens, free);
		return (130);
	}
	tokens = expand(tokens, shell_table, last_status);
	if (!tokens)
		return (1);
	ast = parse(tokens);
	ft_lstclear(&tokens, free);
	if (!ast)
		return (2);
	last_status = exec_ast(ast, shell_table);
	free_ast(ast);
	return (last_status);
}
