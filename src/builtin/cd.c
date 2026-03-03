/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 00:48:09 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 12:41:23 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static int	by_too_many_arguments_error(void);
static int	by_move_to_home(t_shell_table *shell_table);
static int	by_move_to_oldpwd(t_shell_table *shell_table);
static int	move_to_path(const char *absolute_path, t_shell_table *shell_table);

int	cd(t_list *argv, t_shell_table *shell_table)
{
	int	argc;

	argc = ft_lstsize(argv);
	if (argc > 2)
		return (by_too_many_arguments_error());
	if (argc == 1)
		return (by_move_to_home(shell_table));
	if (argc == 2 && argv->next->content)
	{
		if (ft_strncmp((char *)argv->next->content, "~", 2) == 0)
			return (by_move_to_home(shell_table));
		if (ft_strncmp((char *)argv->next->content, "-", 2) == 0)
			return (by_move_to_oldpwd(shell_table));
		return (move_to_path(to_absolute_path((char *)argv->next->content),
				shell_table));
	}
	return (SUCCESS);
}

static int	by_too_many_arguments_error(void)
{
	ft_putstr_fd("Error: cd too many arguments\n", STDERR_FILENO);
	return (1);
}

static int	by_move_to_home(t_shell_table *shell_table)
{
	char	*home;

	home = st_search(shell_table, "HOME");
	if (!home)
	{
		ft_putstr_fd("Error: cd HOME not set\n", STDERR_FILENO);
		return (1);
	}
	return (move_to_path(home, shell_table));
}

static int	by_move_to_oldpwd(t_shell_table *shell_table)
{
	char	*oldpwd;

	oldpwd = st_search(shell_table, "OLDPWD");
	if (!oldpwd)
	{
		ft_putstr_fd("Error: cd OLDPWD not set\n", STDERR_FILENO);
		return (1);
	}
	return (move_to_path(oldpwd, shell_table));
}

static int	move_to_path(const char *absolute_path, t_shell_table *shell_table)
{
	char	*old_pwd;
	char	*new_pwd;
	int		has_insert_error;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (1);
	if (chdir(absolute_path) == -1)
	{
		perror("cd");
		free(old_pwd);
		return (1);
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
	{
		free(old_pwd);
		return (1);
	}
	has_insert_error = st_insert(shell_table, "OLDPWD", old_pwd, true) == 0
		|| st_insert(shell_table, "PWD", new_pwd, true) == 0;
	free(old_pwd);
	free(new_pwd);
	return (has_insert_error);
}
