/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:25:07 by surayama          #+#    #+#             */
/*   Updated: 2025/11/27 16:04:51 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_H
# define DIRECTORY_H

# include <constants.h>
# include <dirent.h>
# include <errno.h>
# include <libft.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>

int	get_directory_entries(const char *path, bool include_hidden,
		t_list **entries);

#endif
