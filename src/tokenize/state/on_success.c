/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:35:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/22 12:44:01 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_list	*on_success(t_token_store *store, char *input)
{
	t_list	*rtv_tokens;

	if (!store)
		return (NULL);
	if (input)
		free(input);
	rtv_tokens = store->tokens;
	store->tokens = NULL;
	if (store->buffer)
		ft_lstclear(&(store->buffer), free);
	return (rtv_tokens);
}
