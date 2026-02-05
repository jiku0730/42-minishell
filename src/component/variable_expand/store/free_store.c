/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:44:15 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 16:28:24 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

void	expand_free_store(t_expand_store *store)
{
	if (!store)
		return ;
	ft_lstclear(&(store->buffer), free);
	ft_lstclear(&(store->tokens), free);
}
