/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expand_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:21:58 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 18:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_WILDCARD_INTERNAL_H
# define EXPAND_WILDCARD_INTERNAL_H

# include "libft.h"
# include <stdbool.h>

# define WILDCARD '*'

t_list	*resolve_wildcard(const char *token);

#endif
