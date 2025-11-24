/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_node(t_hash_node *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	free(node);
}

int	ht_delete(t_hash_table *table, const char *key)
{
	size_t		index;
	t_hash_node	*node;
	t_hash_node	*prev;

	if (!table || !key)
		return (0);
	index = ht_hash(key, table->size);
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
