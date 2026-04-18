/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:13:55 by surayama          #+#    #+#             */
/*   Updated: 2026/04/17 21:31:58 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "constants.h"
# include "libft.h"
# include "parse.h"
# include "shell_table.h"
# include <stdbool.h>

t_list	*expand(t_list *tokens, t_shell_table *shell_table, int last_status);
int		expand_cmd(t_cmd *cmd, t_shell_table *shell_table);
t_list	*expand_tilde(t_list *tokens, t_shell_table *shell_table);
t_list	*expand_question(t_list *tokens, int last_exit_status);
t_list	*expand_parameter(t_list *tokens, t_shell_table *shell_table);
t_list	*expand_wildcard(t_list *tokens);
t_list	*expand_remove_quotes(t_list *tokens);
t_list	*expand_question(t_list *tokens, int last_exit_status);

#endif
