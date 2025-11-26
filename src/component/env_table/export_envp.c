/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:15:41 by urassh            #+#    #+#             */
/*   Updated: 2025/11/26 16:45:48 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env_table.h>

static int	export_envp_entries(char **envp, t_hash_table *env_table);
static char	*export_envp_str(t_hash_node *node);
static void	free_envp_array(char **envp, size_t count);

char	**export_envp(t_hash_table *env_table)
{
	char	**envp;

	if (!env_table)
		return (NULL);
	envp = (char **)ft_calloc(env_table->n_nodes + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	if (export_envp_entries(envp, env_table) == ERROR)
		return (NULL);
	return (envp);
}

static int	export_envp_entries(char **envp, t_hash_table *env_table)
{
	size_t		index;
	size_t		env_index;
	t_hash_node	*node;

	env_index = 0;
	index = 0;
	while (index < env_table->size)
	{
		node = env_table->buckets[index];
		while (node)
		{
			envp[env_index] = export_envp_str(node);
			if (!envp[env_index])
			{
				free_envp_array(envp, env_index);
				return (ERROR);
			}
			env_index++;
			node = node->next;
		}
		index++;
	}
	return (SUCCESS);
}

static char	*export_envp_str(t_hash_node *node)
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

static void	free_envp_array(char **envp, size_t count)
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
}
