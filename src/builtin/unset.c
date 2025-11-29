/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:59:00 by surayama          #+#    #+#             */
/*   Updated: 2025/11/29 20:59:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static void	skip_head_node(t_list **argv);

int	unset(t_list *argv, t_shell_table *shell_table)
{
	char	*key;
	int		result;

	if (!argv || !argv->content)
		return (ERROR);
	result = SUCCESS;
	skip_head_node(&argv);
	while (argv)
	{
		key = (char *)argv->content;
		if (!key)
		{
			result = ERROR;
			skip_head_node(&argv);
			continue ;
		}
		if (!st_delete(shell_table, key))
			result = ERROR;
		skip_head_node(&argv);
	}
	return (result);
}

static void	skip_head_node(t_list **argv)
{
	if (argv && *argv)
		*argv = (*argv)->next;
}
