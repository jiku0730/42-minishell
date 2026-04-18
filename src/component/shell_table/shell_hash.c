/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_table.h"

size_t	st_hash(const char *key, size_t table_size)
{
	const size_t	inital_hash = 5381;
	size_t			hash_num;
	size_t			i;

	if (!key || table_size == 0)
		return (0);
	hash_num = inital_hash;
	i = 0;
	while (key[i])
	{
		hash_num = ((hash_num << 5) + hash_num) + (unsigned char)key[i];
		i++;
	}
	return (hash_num % table_size);
}
