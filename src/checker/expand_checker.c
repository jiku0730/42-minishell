/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:30:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:30:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variable_expand.h"

static void	on_exit_token(t_list *token_list);
static void	print_expanded_tokens(t_list *token_list);

void	expand_checker(char *input, t_shell_table *shell_table)
{
	t_list	*token_list;
	t_list	*expanded_tokens;

	token_list = tokenize(input);
	if (!token_list)
	{
		ft_putstr_fd("Error: tokenize failed\n", STDOUT_FILENO);
		return ;
	}
	if (token_list->content && ft_strncmp(token_list->content, "exit", 5) == 0)
		on_exit_token(token_list);
	expanded_tokens = variable_expand(token_list, shell_table);
	if (!expanded_tokens)
	{
		ft_putstr_fd("Error: variable_expand failed\n", STDOUT_FILENO);
		ft_lstclear(&token_list, free);
		return ;
	}
	print_expanded_tokens(expanded_tokens);
	ft_lstclear(&token_list, free);
	ft_lstclear(&expanded_tokens, free);
}

static void	print_expanded_tokens(t_list *token_list)
{
	t_list	*current;
	int		index;
	char	*content;

	index = 0;
	current = token_list;
	printf("expanded_tokens:\n");
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
