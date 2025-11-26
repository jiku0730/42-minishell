/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 01:46:42 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 01:52:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	on_exit_token(t_list *token_list)
{
	write(STDOUT_FILENO, "exit\n", 5);
	ft_lstclear(&token_list, free);
	exit(0);
}

void	parser_checker(char *input, t_hash_table *env_table)
{
	t_list	*token_list;
	t_ast	*ast_root;

	(void)env_table;
	token_list = tokenize(input);
	if (!token_list)
	{
		write(STDOUT_FILENO, "Error: tokenize failed\n", 23);
		return ;
	}
	if (token_list->content && ft_strncmp(token_list->content, "exit", 5) == 0)
		on_exit_token(token_list);
	ast_root = parser(token_list);
	print_ast(ast_root);
	free_ast(ast_root);
	ft_lstclear(&token_list, free);
}
