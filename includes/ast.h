/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 23:36:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/03 23:37:21 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_ast_type
{
	PIPE,
	CMD
}					t_ast_type;

typedef enum e_redir_kind
{
	R_IN,
	R_OUT_TRUNC,
	R_OUT_APPEND
}					t_redir_kind;

typedef struct s_redir
{
	t_redir_kind	kind;
	char			*filename;
}					t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_list			*redirs;
}					t_cmd;

typedef struct s_ast
{
	t_ast_type		type;
	t_cmd			*cmd;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

void				validate_args(int argc, char const *argv[]);
void				tokenize_from_args(const char *argv[], t_list **head);
t_ast				*build_ast(t_list *head);
int					exec_pipe(t_ast *node, char *const envp[]);
int					exec_ast(t_ast *node, char *const envp[]);

/* ===== トークン系ユーティリティ ===== */
int					is_word(const t_list *node);
int					is_sym(const t_list *node, const char *lit); /* 例: "|" */
int					is_eof(const t_list *node);
const char			*TOK(const t_list *node); /* lex を返す */

/* ===== ASTユーティリティ ===== */
int					push_argv(char ***pargv, const char *s);
void				free_ast_node(t_ast *node);

#endif
