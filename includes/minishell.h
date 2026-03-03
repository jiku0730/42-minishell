/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:14:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/02/13 23:37:35 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "heredoc.h"
# include "libft.h"
# include "parser.h"
# include "prompt.h"
# include "path.h"
# include "remove_quotes.h"
# include "shell_table.h"
# include "tokenize.h"

// callbacks
void	on_input(char *input, t_shell_table *shell_table);

// checkers
void	tokenize_checker(char *input, t_shell_table *shell_table);
void	heredoc_checker(char *input, t_shell_table *shell_table);
void	shell_table_checker(t_shell_table *shell_table);
void	parser_checker(char *input, t_shell_table *shell_table);
void	directory_checker(char *input, t_shell_table *shell_table);
void	path_checker(char *input, t_shell_table *shell_table);
void	builtin_checker(char *input, t_shell_table *shell_table);
void	expand_checker(char *input, t_shell_table *shell_table);
void	remove_quotes_checker(char *input, t_shell_table *shell_table);
void	wildcard_checker(char *input, t_shell_table *shell_table);
void	relative_path_checker(char *input, t_shell_table *shell_table);

#endif
