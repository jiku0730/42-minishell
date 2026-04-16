/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:25 by surayama          #+#    #+#             */
/*   Updated: 2026/04/17 21:23:54 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
int	on_input(char *input, t_shell_table *shell_table, int last_status)
{
	t_list	*tokens;
	t_ast	*ast;
	int		current_status;
=======
static void	update_exit_status(t_shell_table *shell_table, int status)
{
	char	*status_str;

	status_str = ft_itoa(status);
	if (!status_str)
		return ;
	st_insert(shell_table, "?", status_str, false);
	free(status_str);
}

void	on_input(char *input, t_shell_table *shell_table)
{
	t_list	*tokens;
	t_ast	*ast;
	int		status;
>>>>>>> 5796375 (wip: exec_ast の戻り値を $? として shell_table に保存)

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
<<<<<<< HEAD
		return (2);
	current_status = exec_ast(ast, shell_table);
	free_ast(ast);
	return (current_status);
=======
		return ;
	status = exec_ast(ast, shell_table);
	free_ast(ast);
	update_exit_status(shell_table, status);
>>>>>>> 5796375 (wip: exec_ast の戻り値を $? として shell_table に保存)
}
