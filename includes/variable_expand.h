/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expand.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:37:05 by surayama          #+#    #+#             */
/*   Updated: 2026/02/01 22:55:01 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "constants.h"
# include "libft.h"
# include "shell_table.h"

t_list *variable_expand(t_list *tokens, t_shell_table *shell_table);

#endif
