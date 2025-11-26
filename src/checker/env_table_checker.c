/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:53:40 by urassh            #+#    #+#             */
/*   Updated: 2025/11/26 17:04:38 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdio.h>

static void	print_env_table_entries(t_hash_table *env_table);
static void	print_exported_envp(t_hash_table *env_table);

void	env_table_checker(t_hash_table *env_table)
{
	printf("\n========== ENV TABLE ENTRIES ==========\n");
	print_env_table_entries(env_table);
	printf("\n========== EXPORTED ENVP ==========\n");
	print_exported_envp(env_table);
	printf("=======================================\n\n");
}

static void	print_env_table_entries(t_hash_table *env_table)
{
	size_t		i;
	t_hash_node	*node;

	if (!env_table)
	{
		printf("env_table is NULL\n");
		return ;
	}
	printf("Total entries: %zu\n", env_table->n_nodes);
	printf("Table size: %zu\n\n", env_table->size);
	i = 0;
	while (i < env_table->size)
	{
		node = env_table->buckets[i];
		while (node)
		{
			printf("[%zu] %s = %s\n", i, node->key, node->value);
			node = node->next;
		}
		i++;
	}
}

static void	print_exported_envp(t_hash_table *env_table)
{
	char	**envp;
	size_t	i;

	if (!env_table)
	{
		printf("env_table is NULL\n");
		return ;
	}
	envp = export_envp(env_table);
	if (!envp)
	{
		printf("Failed to export envp\n");
		return ;
	}
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		free(envp[i]);
		i++;
	}
	free(envp);
}
