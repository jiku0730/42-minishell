/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:35:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 16:27:40 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "tokenize_internal.h"

t_list	*on_error(t_token_store *store, char *input)
{
	if (input)
		free(input);
	free_store(store);
	return (NULL);
}
