/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:47:35 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 13:50:46 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	on_exit_token(t_list *token_list);
static void	print_tokens(t_list *token_list);

void	tokenize_checker(char *input, t_shell_table *shell_table)
{
	t_list	*token_list;

	(void)shell_table;
	token_list = tokenize(input);
	if (!token_list)
	{
		ft_putstr_fd("Error: tokenize failed\n", STDOUT_FILENO);
		return ;
	}
	if (token_list->content && ft_strncmp(token_list->content, "exit", 5) == 0)
		on_exit_token(token_list);
	print_tokens(token_list);
	ft_lstclear(&token_list, free);
}

static void	print_tokens(t_list *token_list)
{
	t_list	*current;
	int		index;
	char	*content;

	index = 0;
	current = token_list;
	printf("Tokens:\n");
	while (current)
	{
		content = current->content;
		printf("[%d] \"%s\"\n", index, content);
		current = current->next;
		index++;
	}
}

static void	on_exit_token(t_list *token_list)
{
	printf("exit\n");
	ft_lstclear(&token_list, free);
	exit(0);
}
