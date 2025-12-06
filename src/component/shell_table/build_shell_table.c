/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_shell_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:15:23 by urassh            #+#    #+#             */
/*   Updated: 2025/12/01 03:23:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_table.h"

static t_shell_table	*st_create(size_t size);
static int				insert_env_entries(char *const envp[],
							t_shell_table *table);
static int				parse_env_entry(char *env, char **key, char **value);

t_shell_table	*build_shell_table(char *const envp[])
{
	t_shell_table	*table;

	if (!envp)
		return (NULL);
	table = st_create(SHELL_TABLE_INIT_SIZE);
	if (!table)
		return (NULL);
	if (insert_env_entries(envp, table) == ERROR)
		return (NULL);
	return (table);
}

static int	insert_env_entries(char *const envp[], t_shell_table *table)
{
	size_t	i;
	char	*key_tmp;
	char	*value_tmp;

	i = 0;
	while (envp[i])
	{
		if (parse_env_entry(envp[i], &key_tmp, &value_tmp) == ERROR)
			return (ERROR);
		if (!st_insert(table, key_tmp, value_tmp, true))
		{
			free(key_tmp);
			free(value_tmp);
			st_destroy(table);
			return (ERROR);
		}
		free(key_tmp);
		free(value_tmp);
		i++;
	}
	return (SUCCESS);
}

static int	parse_env_entry(char *env, char **key, char **value)
{
	char	*eq_ptr;
	size_t	key_len;

	eq_ptr = ft_strchr(env, '=');
	if (!eq_ptr)
		return (ERROR);
	key_len = eq_ptr - env;
	*key = (char *)malloc(key_len + 1);
	if (!*key)
		return (ERROR);
	ft_strlcpy(*key, env, key_len + 1);
	*value = ft_strdup(eq_ptr + 1);
	if (!*value)
	{
		free(*key);
		return (ERROR);
	}
	return (SUCCESS);
}

static t_shell_table	*st_create(size_t size)
{
	t_shell_table	*table;

	if (size == 0)
		return (NULL);
	table = (t_shell_table *)ft_calloc(1, sizeof(t_shell_table));
	if (!table)
		return (NULL);
	table->buckets = (t_shell_node **)ft_calloc(size, sizeof(t_shell_node *));
	if (!table->buckets)
	{
		free(table);
		return (NULL);
	}
	table->size = size;
	table->n_nodes = 0;
	return (table);
}
