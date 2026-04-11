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
static char	*get_key_from_assignment(const char *assignment);
static char	*get_value_from_assignment(const char *assignment);

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
	char	*value;
	int		result;

	if (!shell_table || !assignment)
		return (ERROR);
	key = get_key_from_assignment(assignment);
	if (!key)
		return (ERROR);
	value = get_value_from_assignment(assignment);
	if (!value)
	{
		free(key);
		return (ERROR);
	}
	if (value[0] == '\0')
		result = st_set_exported(shell_table, key);
	else
		result = st_insert(shell_table, key, value, true);
	free(key);
	free(value);
	if (!result)
		return (ERROR);
	return (SUCCESS);
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

static char	*get_value_from_assignment(const char *assignment)
{
	char	*equal_sign_pos;
	char	*value;

	equal_sign_pos = ft_strchr(assignment, '=');
	if (!equal_sign_pos)
	{
		value = (char *)ft_calloc(1, sizeof(char));
		if (!value)
			return (NULL);
		return (value);
	}
	value = ft_strdup(equal_sign_pos + 1);
	return (value);
}
