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

	if (size == 0)
		return (NULL);
	table = (t_hash_table *)ft_calloc(1, sizeof(t_hash_table));
	if (!table)
		return (NULL);
	table->buckets = (t_hash_node **)ft_calloc(size, sizeof(t_hash_node *));
	if (!table->buckets)
	{
		free(table);
		return (NULL);
	}
	table->size = size;
	table->n_nodes = 0;
	return (table);
}
