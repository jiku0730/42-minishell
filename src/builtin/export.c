/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:29:03 by surayama          #+#    #+#             */
/*   Updated: 2025/11/29 20:55:44 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static void	skip_head_node(t_list **argv);
static int	insert_assignment(t_shell_table *shell_table,
				const char *assignment);
static char	*get_key_from_assignment(const char *assignment);
static char	*get_value_from_assignment(const char *assignment);

int	export(t_list *argv, t_shell_table *shell_table)
{
	if (!argv || !argv->content)
		return (ERROR);
	skip_head_node(&argv);
	while (argv)
	{
		if (insert_assignment(shell_table,
				(const char *)argv->content) == ERROR)
			return (ERROR);
		skip_head_node(&argv);
	}
	return (SUCCESS);
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
	if (!st_insert(shell_table, key, value, true))
	{
		free(key);
		free(value);
		return (ERROR);
	}
	free(key);
	free(value);
	return (SUCCESS);
}

static char	*get_key_from_assignment(const char *assignment)
{
	size_t	i;
	char	*key;

	i = 0;
	while (assignment[i] && assignment[i] != '=')
		i++;
	key = (char *)ft_calloc(i + 1, sizeof(char));
	if (!key)
		return (NULL);
	ft_strlcpy(key, assignment, i + 1);
	return (key);
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
