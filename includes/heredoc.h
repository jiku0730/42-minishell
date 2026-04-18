/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:12:42 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:51 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "constants.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

# include "shell_table.h"
# include <stdbool.h>

t_list	*heredoc(t_list *tokens, t_shell_table *st);
char	*heredoc_prompt(const char *delim, bool expand,
			t_shell_table *st);

char	*expand_heredoc_line(const char *line, t_shell_table *st);

// tmpfile
int		open_tmpfile(char *tmpfile_path);
char	*create_tmpfile(void);

# define HEREDOC_PROMPT "heredoc> "
# define HEREDOC_TMP_PREFIX "/tmp/minishell_heredoc_"
# define HEREDOC_BUFFER 1024

#endif
