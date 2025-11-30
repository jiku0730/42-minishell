/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:16:51 by surayama          #+#    #+#             */
/*   Updated: 2025/11/29 18:09:29 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <limits.h>
# include <shell_table.h>
# include <stdio.h>
# include <unistd.h>

int	echo(t_list *argv, t_shell_table *shell_table);
int	pwd(t_list *argv, t_shell_table *shell_table);
int	export(t_list *argv, t_shell_table *shell_table);
int	unset(t_list *argv, t_shell_table *shell_table);
int	cd(t_list *argv, t_shell_table *shell_table);

#endif
