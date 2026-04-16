/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:29:03 by surayama          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	skip_head_node(t_list **argv);
static int	insert_assignment(t_shell_table *shell_table,
				const char *assignment);
static char	*get_key_from_assignment(const char *assignment);

int	export(t_list *argv, t_shell_table *shell_table)
{
	int	ret;

	if (!argv || !argv->content)
		return (1);
	skip_head_node(&argv);
	if (!argv)
	{
		st_print_env(shell_table);
		return (0);
	}
	ret = 0;
	while (argv)
	{
		if (insert_assignment(shell_table,
				(const char *)argv->content) != 0)
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

static void	print_invalid_id(const char *arg)
{
	ft_putstr_fd("jikussh: export: `", STDERR_FILENO);
	ft_putstr_fd((char *)arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

static int	insert_assignment(t_shell_table *shell_table,
		const char *assignment)
{
	char	*key;
	int		has_equal;

	if (!shell_table || !assignment)
		return (1);
	key = get_key_from_assignment(assignment);
	if (!key)
		return (1);
	if (!st_is_valid_key(key))
	{
		free(key);
		print_invalid_id(assignment);
		return (1);
	}
	has_equal = (ft_strchr(assignment, '=') != NULL);
	if (has_equal)
		st_insert(shell_table, key, ft_strchr(assignment, '=') + 1, true);
	else
		st_set_exported(shell_table, key);
	free(key);
	return (0);
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
