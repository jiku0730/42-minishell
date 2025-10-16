/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:57:51 by urassh            #+#    #+#             */
/*   Updated: 2025/10/16 23:58:16 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	free_store(t_token_store *store)
{
	if (!store)
		return ;
	if (store->buffer)
		ft_lstclear(&(store->buffer), free);
	if (store->tokens)
		ft_lstclear(&(store->tokens), free);
}
