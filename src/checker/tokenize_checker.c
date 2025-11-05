/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:47:35 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 13:48:56 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	on_exit_token(t_list *token_list);
static void	print_tokens(t_list *token_list);

void	tokenize_checker(char *input)
{
	t_list	*token_list;

	token_list = tokenize(input);
	if (!token_list)
	{
		write(STDOUT_FILENO, "Error: tokenize failed\n", 23);
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

	index = 0;
	current = token_list;
	write(STDOUT_FILENO, "Tokens:\n", 8);
	while (current)
	{
		write(STDOUT_FILENO, "[", 1);
		ft_putnbr_fd(index, STDOUT_FILENO);
		write(STDOUT_FILENO, "] \"", 3);
		if (current->content)
			write(STDOUT_FILENO, current->content, ft_strlen(current->content));
		write(STDOUT_FILENO, "\"\n", 2);
		current = current->next;
		index++;
	}
}

static void	on_exit_token(t_list *token_list)
{
	write(STDOUT_FILENO, "exit\n", 5);
	ft_lstclear(&token_list, free);
	exit(0);
}
