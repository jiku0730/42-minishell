/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:55:55 by urassh            #+#    #+#             */
/*   Updated: 2025/11/26 16:49:25 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdio.h>
#include <unistd.h>

static void	on_exit_token(t_list *token_list);
static void	print_tokens(t_list *token_list);
static void	unlink_tmpfiles(t_list *token_list);

void	heredoc_checker(char *input, t_hash_table *env_table)
{
	t_list	*token_list;
	t_list	*heredoced_list;

	(void)env_table;
	token_list = tokenize(input);
	if (!token_list)
	{
		printf("Error: tokenize failed\n");
		return ;
	}
	if (token_list->content && ft_strncmp(token_list->content, "exit", 5) == 0)
		on_exit_token(token_list);
	heredoced_list = heredoc(token_list);
	if (!heredoced_list)
	{
		printf("Error: heredoc failed\n");
		ft_lstclear(&token_list, free);
		return ;
	}
	print_tokens(heredoced_list);
	unlink_tmpfiles(heredoced_list);
	ft_lstclear(&heredoced_list, free);
}

static void	print_tokens(t_list *token_list)
{
	t_list	*current;
	int		index;

	index = 0;
	current = token_list;
	printf("here_doced_tokens:\n");
	while (current)
	{
		printf("[%d] \"", index);
		if (current->content)
			printf("%s", (char *)current->content);
		printf("\"\n");
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

static void	unlink_tmpfiles(t_list *token_list)
{
	t_list	*current;

	current = token_list;
	while (current)
	{
		if (current->content && ft_strncmp(current->content, HEREDOC_TMP_PREFIX,
				ft_strlen(HEREDOC_TMP_PREFIX)) == 0)
			unlink((char *)current->content);
		current = current->next;
	}
}
