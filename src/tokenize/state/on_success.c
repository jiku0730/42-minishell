/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:35:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/17 00:30:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_list	*on_success(t_token_store *store)
{
	t_list	*tokens;

	if (!store)
		return (NULL);
	tokens = store->tokens;
	store->tokens = NULL;
	if (store->buffer)
		ft_lstclear(&(store->buffer), free);
	return (tokens);
}
