/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:38:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/01/08 10:37:36 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* prevent re-include-------------------------------------------------------- */
#ifndef EXECUTE_H
# define EXECUTE_H

/* include header file------------------------------------------------------- */
# include "parse.h"
# include "shell_table.h"

/* main function------------------------------------------------------------- */
int					exec_ast(t_ast *node, t_shell_table *shell_table);
int					exec_cmd(t_ast *node, t_shell_table *shell_table);
int					exec_external_cmd(char **argv, t_shell_table *shell_table);
char				*find_exec_path(const char *cmd, t_shell_table *shell_table);
int					exec_pipe(t_ast *node, t_shell_table *shell_table);
void				exec_left_child(t_ast *node, \
						t_shell_table *shell_table, int fd[2]);
void				exec_right_child(t_ast *node, \
						t_shell_table *shell_table, int fd[2]);
int					exec_redirs(t_list *redirs);
char				**list_to_argv(t_list *lst);
int					ft_wifexited(int exit_status);
int					ft_wexitstatus(int exit_status);

#endif
