/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:36:50 by urassh            #+#    #+#             */
/*   Updated: 2025/11/27 12:02:52 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include <libft.h>
# include <stdbool.h>

# define WILDCARD '*'

t_list	*filter_pattern(t_list *source, const char *pattern);

#endif
