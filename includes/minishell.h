/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:14:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/20 15:56:35 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "constants.h"
# include "libft.h"
# include "prompt.h"
# include "tokenize.h"
# include "heredoc.h"

// callbacks
void	on_input(char *input);

// checkers
void	tokenize_checker(char *input);
void	heredoc_checker(char *input);

#endif
