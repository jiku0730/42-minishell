/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:18 by urassh            #+#    #+#             */
/*   Updated: 2025/11/27 14:54:45 by urassh           ###   ########.fr       */
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

void	prompt(void (*handler)(char *input, t_shell_table *shell_table),
			t_shell_table *shell_table);

# define PROMPT "minishell$ "

#endif
