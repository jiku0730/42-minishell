/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:38:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 11:51:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "constants.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/* define part--------------------------------------------------------------- */
typedef enum e_ast_type
{
	PIPE,
	CMD
}					t_ast_type;

typedef enum e_redir_kind
{
	R_IN,
	R_OUT_TRUNC,
	R_OUT_APPEND,
	R_NOT_FOUND
}					t_redir_kind;

typedef struct s_redir
{
	t_redir_kind	kind;
	char			*filename;
}					t_redir;

typedef struct s_cmd
{
	t_list			*argv;
	t_list			*redirs;
}					t_cmd;

typedef struct s_ast
{
	t_ast_type		type;
	t_cmd			*cmd;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

/* main function------------------------------------------------------------- */
t_ast			*parse(t_list *token_head);

/* AST's token utils--------------------------------------------------------- */
bool			is_word(const t_list *node);
bool			is_symbol(const t_list *node, const char *literal);
bool			is_redir(const t_list *node);

/* AST's Utils--------------------------------------------------------------- */
t_ast			*new_ast_node(t_ast_type type);
t_cmd			*new_cmd(void);
t_redir			*new_redir(t_redir_kind kind, const char *filename);
bool			add_redir_to_cmd(t_cmd *cmd, t_redir_kind kind,
					const char *file);
bool			add_argv_to_cmd(t_cmd *cmd, const char *arg);

/* free utils function------------------------------------------------------- */
void			free_cmd(t_cmd *cmd);
void			free_ast(t_ast *node);

/* test print function------------------------------------------------------- */
void			print_branch_line(const char *prefix, bool is_last,
					const char *text);
void			build_child_prefix(const char *prefix, bool is_last,
					char *buffer, size_t size);
void			print_argv_item(t_list *node, int index);
const char		*get_redir_symbol(t_redir *redir);
void			print_redir_entry(t_redir *redir, int index);
void			print_argv_line(const char *prefix, bool is_last,
					t_list *argv);
void			print_redir_line(const char *prefix, bool is_last,
					t_list *redirs);
void			print_pipe_children(t_ast *node, const char *prefix);
void			print_pipe_node(t_ast *node, const char *prefix, bool is_last);
void			print_ast_node(t_ast *node, const char *prefix, bool is_last);
void			print_ast(t_ast *ast_root);
#endif
