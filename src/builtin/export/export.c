/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:29:03 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 19:31:33 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	skip_head_node(t_list **argv);
static int	insert_assignment(t_shell_table *shell_table,
				const char *assignment);
static int	insert_key_value(t_shell_table *shell_table,
				const char *key, const char *assignment);
static char	*get_key_from_assignment(const char *assignment);

int	export(t_list *argv, t_shell_table *shell_table)
{
	if (!argv || !argv->content)
		return (1);
	skip_head_node(&argv);
	if (!argv)
	{
		st_print_env(shell_table);
		return (0);
	}
	while (argv)
	{
		if (insert_assignment(shell_table,
				(const char *)argv->content) == ERROR)
			return (1);
		skip_head_node(&argv);
	}
	return (0);
}

static void	skip_head_node(t_list **argv)
{
	if (argv && *argv)
		*argv = (*argv)->next;
}

static int	insert_assignment(t_shell_table *shell_table,
		const char *assignment)
{
	char	*key;
	int		result;

	if (!shell_table || !assignment)
		return (ERROR);
	key = get_key_from_assignment(assignment);
	if (!key)
		return (ERROR);
	if (!ft_strchr(assignment, '='))
		result = st_set_exported(shell_table, key);
	else
		result = insert_key_value(shell_table, key, assignment);
	free(key);
	if (result <= 0)
	{
		print_export_error(assignment);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	insert_key_value(t_shell_table *shell_table,
		const char *key, const char *assignment)
{
	char	*equal_pos;
	char	*value;
	int		result;

	equal_pos = ft_strchr(assignment, '=');
	value = ft_strdup(equal_pos + 1);
	if (!value)
		return (ERROR);
	result = st_insert(shell_table, key, value, true);
	free(value);
	return (result);
}

static char	*get_key_from_assignment(const char *assignment)
{
	char	*equal_sign_pos;
	size_t	key_len;

	equal_sign_pos = ft_strchr(assignment, '=');
	if (!equal_sign_pos)
		return (ft_strdup(assignment));
	key_len = equal_sign_pos - assignment;
	return (ft_substr(assignment, 0, key_len));
}
