/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_hash_table	*ht_create(size_t size)
{
	t_hash_table	*table;
	size_t			i;

	if (size == 0)
		return (NULL);
	table = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (!table)
		return (NULL);
	table->buckets = (t_hash_node **)malloc(sizeof(t_hash_node *) * size);
	if (!table->buckets)
	{
		free(table);
		return (NULL);
	}
	table->size = size;
	table->n_nodes = 0;
	i = 0;
	while (i < size)
	{
		table->buckets[i] = NULL;
		i++;
	}
	return (table);
}
