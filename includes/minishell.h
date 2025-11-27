/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:14:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 14:54:45 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "shell_table.h"
# include "heredoc.h"
# include "libft.h"
# include "prompt.h"
# include "tokenize.h"
# include "parser.h"

// callbacks
void	on_input(char *input, t_shell_table *shell_table);

// checkers
void	tokenize_checker(char *input, t_shell_table *shell_table);
void	heredoc_checker(char *input, t_shell_table *shell_table);
void	shell_table_checker(t_shell_table *shell_table);
void	parser_checker(char *input, t_shell_table *shell_table);
#endif
