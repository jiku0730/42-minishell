/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:18 by urassh            #+#    #+#             */
/*   Updated: 2025/10/01 15:48:29 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_H
# define CONSOLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#include "libft.h"

int			console(int (*handler)(char *input));

#define CONSOLE_BUFFER_SIZE 1024
#define PROMPT "minishell$ "

#endif
