/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:59:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	skip_head_node(t_list **argv);

static int	unset_one(t_shell_table *shell_table, const char *key)
{
	if (!key)
		return (1);
	if (!st_is_valid_key(key))
	{
		ft_putstr_fd("jikussh: unset: `", STDERR_FILENO);
		ft_putstr_fd((char *)key, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		return (1);
	}
	st_delete(shell_table, key);
	return (0);
}

int	unset(t_list *argv, t_shell_table *shell_table)
{
	int		ret;

	if (!argv || !argv->content)
		return (1);
	ret = 0;
	skip_head_node(&argv);
	while (argv)
	{
		if (unset_one(shell_table, (char *)argv->content) != 0)
			ret = 1;
		skip_head_node(&argv);
	}
	return (ret);
}

static void	skip_head_node(t_list **argv)
{
	if (argv && *argv)
		*argv = (*argv)->next;
}
