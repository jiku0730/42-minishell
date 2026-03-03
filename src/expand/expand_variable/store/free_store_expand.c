/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:44:15 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:14:47 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../expand_variable_internal.h"
#include "expand.h"

void	free_store_expand(t_expand_store *store)
{
	if (!store)
		return ;
	ft_lstclear(&(store->buffer), free);
	ft_lstclear(&(store->tokens), free);
}
