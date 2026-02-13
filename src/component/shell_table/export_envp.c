/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:15:41 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_table.h"

static int	count_exported_nodes(t_shell_table *shell_table);
static int	export_envp_entries(char **envp, t_shell_table *shell_table);
static char	*export_envp_str(t_shell_node *node);
static int	throw_export_envp(char **envp, size_t count);

char	**export_envp(t_shell_table *shell_table)
{
	char	**envp;
	int		count;

	if (!shell_table)
		return (NULL);
	count = count_exported_nodes(shell_table);
	envp = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	if (export_envp_entries(envp, shell_table) == ERROR)
		return (NULL);
	return (envp);
}

static int	count_exported_nodes(t_shell_table *shell_table)
{
	size_t			index;
	t_shell_node	*node;
	int				count;

	count = 0;
	index = 0;
	while (index < shell_table->size)
	{
		node = shell_table->buckets[index];
		while (node)
		{
			if (node->exported)
				count++;
			node = node->next;
		}
		index++;
	}
	return (count);
}

static int	export_envp_entries(char **envp, t_shell_table *shell_table)
{
	size_t			index;
	size_t			env_index;
	t_shell_node	*node;

	env_index = 0;
	index = 0;
	while (index < shell_table->size)
	{
		node = shell_table->buckets[index];
		while (node)
		{
			if (node->exported)
			{
				envp[env_index] = export_envp_str(node);
				if (!envp[env_index])
					return (throw_export_envp(envp, env_index));
				env_index++;
			}
			node = node->next;
		}
		index++;
	}
	return (SUCCESS);
}

static char	*export_envp_str(t_shell_node *node)
{
	char	*result;
	size_t	key_len;
	size_t	value_len;

	key_len = ft_strlen(node->key);
	value_len = ft_strlen(node->value);
	result = (char *)malloc(key_len + value_len + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, node->key, key_len + 1);
	result[key_len] = '=';
	ft_strlcpy(result + key_len + 1, node->value, value_len + 1);
	return (result);
}

static int	throw_export_envp(char **envp, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(envp[i]);
		envp[i] = NULL;
		i++;
	}
	free(envp);
	return (ERROR);
}
