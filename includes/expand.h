/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:13:55 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 18:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "constants.h"
# include "libft.h"
# include "shell_table.h"
# include <stdbool.h>

t_list	*expand(t_list *tokens, t_shell_table *shell_table);
t_list	*expand_parameter(t_list *tokens, t_shell_table *shell_table);
t_list	*expand_tilde(t_list *tokens, t_shell_table *shell_table);
t_list	*expand_wildcard(t_list *tokens);
t_list	*expand_remove_quotes(t_list *tokens);

#endif
