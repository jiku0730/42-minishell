/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:14:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/16 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "execute.h"
# include "expand.h"
# include "heredoc.h"
# include "libft.h"
# include "parse.h"
# include "prompt.h"
# include "path.h"
# include "shell_table.h"
# include "signal_handler.h"
# include "tokenize.h"

// callbacks
void	on_input(char *input, t_shell_table *shell_table);

#endif
