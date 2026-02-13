/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:51 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

char	*to_absolute(const char *path);
t_list	*append_path(t_list **dest, const char *content);
t_list	*append_path_list(t_list **dest, const char *content);

#endif
