/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:09:25 by surayama          #+#    #+#             */
/*   Updated: 2026/01/17 02:18:22 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "constants.h"
# include "libft.h"
# include <stdlib.h>

t_list		*tokenize(char *input);

// is specific
bool		is_quote(char c);
bool		is_operator_char(char c);
bool		is_operator(const char *str);
size_t		operator_length(const char *str);
bool		is_parenthesis(char c);

#endif
