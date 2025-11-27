/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:14:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 01:55:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "env_table.h"
# include "heredoc.h"
# include "libft.h"
# include "prompt.h"
# include "tokenize.h"
# include "parser.h"

// callbacks
void	on_input(char *input, t_hash_table *env_table);

// checkers
void	tokenize_checker(char *input, t_hash_table *env_table);
void	heredoc_checker(char *input, t_hash_table *env_table);
void	env_table_checker(t_hash_table *env_table);
void	parser_checker(char *input, t_hash_table *env_table);
#endif
