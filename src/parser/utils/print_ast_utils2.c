/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:39:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/20 11:49:54 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_redir_entry(t_redir *redir, int index)
{
	const char	*symbol;
	const char	*filename;

	symbol = get_redir_symbol(redir);
	filename = "";
	if (redir && redir->filename)
		filename = redir->filename;
	printf("[%d].%s%s", index + 1, symbol, filename);
}

void	print_argv_line(const char *prefix, bool is_last, t_list *argv)
{
	t_list	*current;
	int		index;

	printf("%s", prefix);
	if (is_last)
		printf("`-- argv: ");
	else
		printf("|-- argv: ");
	if (!argv)
	{
		printf("(empty)\n");
		return ;
	}
	current = argv;
	index = 0;
	while (current)
	{
		print_argv_item(current, index);
		current = current->next;
		index++;
	}
	printf("\n");
}

void	print_redir_line(const char *prefix, bool is_last, t_list *redirs)
{
	t_list	*current;
	int		index;

	printf("%s", prefix);
	if (is_last)
		printf("`-- redirs: ");
	else
		printf("|-- redirs: ");
	if (!redirs)
	{
		printf("(empty)\n");
		return ;
	}
	current = redirs;
	index = 0;
	while (current)
	{
		print_redir_entry((t_redir *)current->content, index);
		current = current->next;
		index++;
	}
	printf("\n");
}

void	print_pipe_children(t_ast *node, const char *prefix)
{
	bool	has_right;

	has_right = false;
	if (node->right)
		has_right = true;
	if (node->left)
	{
		if (has_right)
			print_ast_node(node->left, prefix, false);
		else
			print_ast_node(node->left, prefix, true);
	}
	else if (has_right)
		print_ast_node(NULL, prefix, false);
	if (has_right)
		print_ast_node(node->right, prefix, true);
	else if (!node->left)
		print_ast_node(NULL, prefix, true);
}
