/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tokenize_private.h"

void	by_last(t_token_store *store, t_token_state *state, char current)
{
	(void)current;
	if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
		*state = ON_SUCCESS;
}
