/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/05 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ht_search(t_hash_table *table, const char *key)
{
	size_t		index;
	t_hash_node	*node;

	if (!table || !key)
		return (NULL);
	index = ht_hash(key, table->size);
	node = table->buckets[index];
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
