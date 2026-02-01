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

t_list		*on_error(t_expand_store *store, char *token)
{
	if (token)
		free(token);
	if (store)
		free_store(store);
	return (NULL);
}
