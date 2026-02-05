/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_normal_internal.h"

void	by_space(t_token_store *store, t_token_state *state, char current)
{
	(void)current;
	if (push_token(store) == ERROR)
		*state = ON_ERROR;
	else
		*state = IN_NORMAL;
}
