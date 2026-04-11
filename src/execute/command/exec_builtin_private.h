/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 00:00:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/11 00:00:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_BUILTIN_PRIVATE_H
# define EXEC_BUILTIN_PRIVATE_H

# include "builtin.h"
# include "execute.h"

typedef int					(*t_builtin_fn)(t_list *, t_shell_table *);

typedef struct s_builtin_entry
{
	const char		*name;
	t_builtin_fn	func;
}	t_builtin_entry;

#endif
