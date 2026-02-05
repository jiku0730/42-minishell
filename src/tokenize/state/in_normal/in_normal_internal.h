/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_normal_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_NORMAL_INTERNAL_H
# define IN_NORMAL_INTERNAL_H

# include "../../tokenize_private.h"

void	by_last(t_token_store *store, t_token_state *state, char current);
void	by_space(t_token_store *store, t_token_state *state, char current);
void	by_quote(t_token_store *store, t_token_state *state, char current);
void	by_operator(t_token_store *store, t_token_state *state, char current);
void	by_parenthesis(t_token_store *store, t_token_state *state,
			char current);

#endif
