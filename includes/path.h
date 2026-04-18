/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 17:15:58 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

char	*to_absolute_path(const char *path);
t_list	*append_path(t_list **dest, const char *content);
t_list	*resolve_relative_path(t_list *tokens);
char	*join_path(const char *path_before, const char *path_after);

#endif
