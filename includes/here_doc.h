/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:12:42 by urassh            #+#    #+#             */
/*   Updated: 2025/11/20 15:06:36 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "constants.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <unistd.h>

t_list	*here_doc(t_list *tokens);
t_list	*here_doc_prompt(const char *delimiter);

# define HEREDOC_PROMPT "heredoc> "
# define HEREDOC_BUFFER 1024

#endif
