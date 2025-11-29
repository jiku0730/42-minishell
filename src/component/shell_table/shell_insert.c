/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/27 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell_table.h>

static t_shell_node	*create_node(const char *key, const char *value,
		bool exported)
{
	t_shell_node	*node;

	node = (t_shell_node *)ft_calloc(1, sizeof(t_shell_node));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	node->value = ft_strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->exported = exported;
	return (node);
}

static int	update_existing_node(t_shell_node *node, const char *value)
{
	char	*new_value;

	new_value = ft_strdup(value);
	if (!new_value)
		return (0);
	free(node->value);
	node->value = new_value;
	return (1);
}

int	st_insert(t_shell_table *table, const char *key, const char *value,
		bool exported)
{
	size_t			index;
	t_shell_node	*node;
	t_shell_node	*new_node;

	if (!table || !key || !value)
		return (0);
	index = st_hash(key, table->size);
	node = table->buckets[index];
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
			return (update_existing_node(node, value));
		node = node->next;
	}
	new_node = create_node(key, value, exported);
	if (!new_node)
		return (0);
	new_node->next = table->buckets[index];
	table->buckets[index] = new_node;
	table->n_nodes++;
	return (1);
}

int	st_set_exported(t_shell_table *table, const char *key)
{
	size_t			index;
	t_shell_node	*node;
	t_shell_node	*new_node;

	if (!table || !key)
		return (0);
	index = st_hash(key, table->size);
	node = table->buckets[index];
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
		{
			node->exported = true;
			return (1);
		}
		node = node->next;
	}
	new_node = create_node(key, "", true);
	if (!new_node)
		return (0);
	new_node->next = table->buckets[index];
	table->buckets[index] = new_node;
	table->n_nodes++;
	return (1);
}
