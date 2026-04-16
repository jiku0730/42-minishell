/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:18 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:51 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "constants.h"
# include "shell_table.h"
# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <unistd.h>

void	prompt(int (*handler)(char *input, t_shell_table *shell_table),
				t_shell_table *shell_table);

#endif
