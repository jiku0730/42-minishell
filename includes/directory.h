/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:25:07 by surayama          #+#    #+#             */
/*   Updated: 2025/11/27 15:30:16 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_H
# define DIRECTORY_H

# include <libft.h>
# include <stdbool.h>

int		get_directory_entries(const char *path, bool include_hidden,
			t_list **entries);

#endif
