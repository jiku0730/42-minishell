/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:12:42 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 15:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "constants.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <unistd.h>

t_list	*heredoc(t_list *tokens);
char	*heredoc_prompt(const char *delimiter);

# define HEREDOC_PROMPT "heredoc> "
# define HEREDOC_BUFFER 1024

#endif
