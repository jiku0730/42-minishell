/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:57:42 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/20 11:57:27 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_branch_line(const char *prefix, bool is_last, const char *text)
{
	printf("%s", prefix);
	if (is_last)
		printf("`-- %s\n", text);
	else
		printf("|-- %s\n", text);
}

void	build_child_prefix(const char *prefix, bool is_last,
			char *buffer, size_t size)
{
	ft_strlcpy(buffer, prefix, size);
	if (is_last)
		ft_strlcat(buffer, "    ", size);
	else
		ft_strlcat(buffer, "|   ", size);
}

static const char	*get_argv_value(t_list *node)
{
	if (node && node->content)
		return ((const char *)node->content);
	return ("");
}

const char	*get_redir_symbol(t_redir *redir)
{
	static const char	*kind_str[] = {"<", "<<", ">", ">>"};

	if (!redir)
		return ("?");
	if (R_IN <= redir->kind && redir->kind <= R_OUT_APPEND)
		return (kind_str[redir->kind]);
	return ("?");
}

void	print_argv_item(t_list *node, int index)
{
	if (index > 0)
		printf(" ");
	printf("[%d].%s", index + 1, get_argv_value(node));
}
