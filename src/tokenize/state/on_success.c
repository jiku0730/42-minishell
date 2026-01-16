/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:35:00 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 14:34:32 by kjikuhar         ###   ########.fr       */
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
	ft_lstclear(&(store->buffer), free);
	return (rtv_tokens);
}
