/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 01:46:42 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	on_exit_token(t_list *token_list)
{
	printf("exit\n");
	ft_lstclear(&token_list, free);
	exit(0);
}

void	parse_checker(char *input, t_shell_table *shell_table)
{
	t_list	*token_list;
	t_ast	*ast_root;

	(void)shell_table;
	token_list = tokenize(input);
	if (!token_list)
	{
		printf("Error: tokenize failed\n");
		return ;
	}
	if (token_list->content && ft_strncmp(token_list->content, "exit", 5) == 0)
		on_exit_token(token_list);
	ast_root = parse(token_list);
	print_ast(ast_root);
	free_ast(ast_root);
	ft_lstclear(&token_list, free);
}
