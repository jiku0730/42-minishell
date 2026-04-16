/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shell_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:11:42 by surayama          #+#    #+#             */
/*   Updated: 2025/12/06 16:17:45 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_table.h"

static void	print_exported_node(t_shell_node *node)
{
	if (node->value)
		printf("declare -x %s=\"%s\"\n", node->key, node->value);
	else
		printf("declare -x %s\n", node->key);
}

void	st_print_env(t_shell_table *table)
{
	size_t			i;
	t_shell_node	*node;

	i = 0;
	while (i < table->size)
	{
		node = table->buckets[i];
		while (node)
		{
			if (node->exported)
				print_exported_node(node);
			node = node->next;
		}
		i++;
	}
}
