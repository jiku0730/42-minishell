/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:52:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:52:01 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	on_exit_token(t_list *token_list);
static void	print_tokens(t_list *token_list, const char *title);

void	remove_quotes_checker(char *input, t_shell_table *shell_table)
{
	t_list	*token_list;
	t_list	*result;

	(void)shell_table;
	token_list = tokenize(input);
	if (!token_list)
	{
		ft_putstr_fd("Error: tokenize failed\n", STDOUT_FILENO);
		return ;
	}
	if (token_list->content && ft_strncmp(token_list->content, "exit", 5) == 0)
		on_exit_token(token_list);
	print_tokens(token_list, "Before remove_quote");
	result = expand_remove_quotes(token_list);
	if (!result)
	{
		ft_putstr_fd("Error: remove_quote failed\n", STDOUT_FILENO);
		ft_lstclear(&token_list, free);
		return ;
	}
	print_tokens(result, "After remove_quote");
	ft_lstclear(&result, free);
}

static void	print_tokens(t_list *token_list, const char *title)
{
	t_list	*current;
	int		index;
	char	*content;

	index = 0;
	current = token_list;
	printf("\n%s:\n", title);
	while (current)
	{
		content = current->content;
		printf("[%d] \"%s\"\n", index, content);
		current = current->next;
		index++;
	}
	printf("\n");
}

static void	on_exit_token(t_list *token_list)
{
	printf("exit\n");
	ft_lstclear(&token_list, free);
	exit(0);
}
