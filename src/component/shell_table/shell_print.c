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

void	st_print_env(t_shell_table *table)
{
	size_t			i;
	t_shell_node	*node;

	while (i < table->size)
	{
		node = table->buckets[i];
		while (node)
		{
			if (node->exported)
			{
				if (node->value && node->value[0] != '\0')
					printf("%s=%s\n", node->key, node->value);
				else
					printf("%s=''\n", node->key);
			}
			node = node->next;
		}
		i++;
	}
}
