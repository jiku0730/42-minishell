/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:30:04 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/11 18:30:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_builtin_private.h"

static t_builtin_fn	find_builtin(const char *name)
{
	static const t_builtin_entry	g[] = {
	{"echo", echo},
	{"pwd", pwd},
	{"cd", cd},
	{"export", export},
	{"unset", unset},
	{"exit", builtin_exit},
	{NULL, NULL}
	};
	int								i;

	i = 0;
	while (g[i].name)
	{
		if (ft_strncmp(name, g[i].name, ft_strlen(g[i].name) + 1) == 0)
			return (g[i].func);
		i++;
	}
	return (NULL);
}

int	exec_builtin(t_ast *node, t_shell_table *shell_table)
{
	t_builtin_fn	fn;
	char			*name;

	if (!node->cmd->argv || !node->cmd->argv->content)
		return (-1);
	name = (char *)node->cmd->argv->content;
	fn = find_builtin(name);
	if (!fn)
		return (-1);
	return (fn(node->cmd->argv, shell_table));
}
