/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:38:01 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:41:29 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

t_list	*expand_on_success(t_expand_store *store, char *token)
{
	t_list	*expanded_tokens;

	(void)token;
	if (!store)
		return (NULL);
	expanded_tokens = store->tokens;
	store->tokens = NULL;
	ft_lstclear(&(store->buffer), free);
	return (expanded_tokens);
}
