/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/27 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell_table.h>

static void	free_node(t_shell_node *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	free(node);
}

int	st_delete(t_shell_table *table, const char *key)
{
	size_t			index;
	t_shell_node	*node;
	t_shell_node	*prev;

	if (!table || !key)
		return (0);
	index = st_hash(key, table->size);
	node = table->buckets[index];
	prev = NULL;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
		{
			if (prev)
				prev->next = node->next;
			else
				table->buckets[index] = node->next;
			free_node(node);
			table->n_nodes--;
			return (1);
		}
		prev = node;
		node = node->next;
	}
	return (0);
}
