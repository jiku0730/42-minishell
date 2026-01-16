/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:57:51 by urassh            #+#    #+#             */
/*   Updated: 2026/01/16 14:35:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	free_store(t_token_store *store)
{
	if (!store)
		return ;
	ft_lstclear(&(store->buffer), free);
	ft_lstclear(&(store->tokens), free);
}
