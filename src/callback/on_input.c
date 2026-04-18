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

static bool	has_valid_heredoc(t_list *tokens)
{
	while (tokens)
	{
		if (ft_strncmp(tokens->content, "<<", 3) == 0)
			if (!tokens->next || !tokens->next->content)
				return (false);
		tokens = tokens->next;
	}
	return (true);
}

int	on_input(char *input, t_shell_table *shell_table, int last_status)
{
	t_list	*tokens;
	t_ast	*ast;
	int		current_status;

	tokens = tokenize(input);
	if (!tokens)
		return (2);
	if (!has_valid_heredoc(tokens))
	{
		ft_lstclear(&tokens, free);
		return (2);
	}
	if (!heredoc(tokens, shell_table))
	{
		ft_lstclear(&tokens, free);
		return (130);
	}
	shell_table->last_status = last_status;
	ast = parse(tokens);
	ft_lstclear(&tokens, free);
	if (!ast)
		return (2);
	current_status = exec_ast(ast, shell_table);
	free_ast(ast);
	return (current_status);
}
