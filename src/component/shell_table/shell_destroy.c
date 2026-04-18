/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_table.h"

static void	free_chain(t_shell_node *node)
{
	t_shell_node	*next;

	while (node)
	{
		next = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}
}

void	st_destroy(t_shell_table *table)
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
