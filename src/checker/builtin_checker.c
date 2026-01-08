/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:32:40 by surayama          #+#    #+#             */
/*   Updated: 2025/12/06 16:19:06 by surayama         ###   ########.fr       */
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
	if (builtin_func)
		builtin_func(tokens, shell_table);
	ft_lstclear(&tokens, free);
}
