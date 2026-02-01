/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:44:15 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:45:46 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"

void	free_store(t_expand_store *store)
{
	if (!store)
		return ;
	ft_lstclear(&(store->buffer), free);
	ft_lstclear(&(store->tokens), free);
}
