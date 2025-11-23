/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/11/23 15:09:38 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ht_hash(const char *key, size_t table_size)
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
