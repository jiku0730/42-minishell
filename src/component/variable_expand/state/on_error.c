/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:42:03 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:45:40 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variable_expand.h"
#include "variable_expand_internal.h"

t_list		*expand_on_error(t_expand_store *store, char *token)
{
	if (token)
		free(token);
	if (store)
		expand_free_store(store);
	return (NULL);
}
