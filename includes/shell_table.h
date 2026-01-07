/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/12/06 16:22:11 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_TABLE_H
# define SHELL_TABLE_H

# include "constants.h"
# include "libft.h"
# include <stdbool.h>
# include <stdio.h>

# define SHELL_TABLE_INIT_SIZE 256

typedef struct s_shell_node
{
	char				*key;
	char				*value;
	bool				exported;
	struct s_shell_node	*next;
}						t_shell_node;

typedef struct s_shell_table
{
	t_shell_node		**buckets;
	size_t				size;
	size_t				n_nodes;
}						t_shell_table;

// shell_table operations
size_t					st_hash(const char *key, size_t table_size);
int						st_insert(t_shell_table *table, const char *key,
							const char *value, bool exported);
int						st_set_exported(t_shell_table *table, const char *key);
char					*st_search(t_shell_table *table, const char *key);
int						st_delete(t_shell_table *table, const char *key);
void					st_destroy(t_shell_table *table);
void					st_print_env(t_shell_table *table);

// shell_table specific operations
t_shell_table			*build_shell_table(char *const envp[]);
char					**export_envp(t_shell_table *shell_table);

#endif
