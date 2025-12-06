/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:32:40 by surayama          #+#    #+#             */
/*   Updated: 2025/12/06 15:49:36 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "minishell.h"

void	builtin_checker(char *input, t_shell_table *shell_table)
{
	t_list	*tokens;
	int		(*builtin_func)(t_list *, t_shell_table *);

	builtin_func = export;
	tokens = tokenize(input);
	if (!tokens)
		return ;
	if (ft_strncmp((char *)tokens->content, "export", 7) == 0)
	{
		builtin_func(tokens, shell_table);
		shell_table_checker(shell_table);
	}
	else if (builtin_func)
		builtin_func(tokens, shell_table);
	ft_lstclear(&tokens, free);
}
