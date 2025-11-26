/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_chain(t_hash_node *node)
{
	t_hash_node	*next;

	while (node)
	{
		next = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}
}

void	ht_destroy(t_hash_table *table)
{
	size_t	i;

	if (!table)
		return ;
	if (table->buckets)
	{
		i = 0;
		while (i < table->size)
		{
			free_chain(table->buckets[i]);
			i++;
		}
		free(table->buckets);
	}
	free(table);
}
