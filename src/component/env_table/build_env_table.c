/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:15:23 by urassh            #+#    #+#             */
/*   Updated: 2025/11/26 17:01:50 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env_table.h>

static int		insert_env_entries(char **envp, t_hash_table *table);
static int		parse_env_entry(char *env, char **key, char **value);

t_hash_table	*build_env_table(char **envp)
{
	t_hash_table	*table;

	if (!envp)
		return (NULL);
	table = ht_create(ENV_TABLE_INIT_SIZE);
	if (!table)
		return (NULL);
	if (insert_env_entries(envp, table) == ERROR)
		return (NULL);
	return (table);
}

static int	insert_env_entries(char **envp, t_hash_table *table)
{
	size_t	i;
	char	*key_tmp;
	char	*value_tmp;

	while (envp[i])
	{
		if (parse_env_entry(envp[i], &key_tmp, &value_tmp) == ERROR)
			return (ERROR);
		if (!ht_insert(table, key_tmp, value_tmp))
		{
			free(key_tmp);
			free(value_tmp);
			ht_destroy(table);
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
