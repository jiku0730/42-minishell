/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:42:03 by surayama          #+#    #+#             */
/*   Updated: 2026/02/07 00:15:10 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../expand_variable_internal.h"
#include "expand.h"

t_list	*on_error_expand(t_expand_store *store, char *token)
{
	(void)token;
	if (store)
		free_store_expand(store);
	return (NULL);
}
