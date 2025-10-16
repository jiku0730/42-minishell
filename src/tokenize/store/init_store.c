/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:57:51 by urassh            #+#    #+#             */
/*   Updated: 2025/10/16 23:58:19 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_token_store	*init_store(void)
{
	t_token_store	*store;

	store = (t_token_store *)malloc(sizeof(t_token_store));
	if (!store)
		return (NULL);
	store->tokens = NULL;
	store->buffer = NULL;
	return (store);
}
