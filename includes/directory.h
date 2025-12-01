/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:25:07 by surayama          #+#    #+#             */
/*   Updated: 2025/12/01 03:28:22 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_H
# define DIRECTORY_H

# include "constants.h"
# include <dirent.h>
# include <errno.h>
# include "libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>

int	get_directory_entries(const char *path, bool include_hidden,
		t_list **entries);
int	get_directory_all_entries(const char *path, bool include_hidden,
		t_list **entries);

#endif
