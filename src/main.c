/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/03/03 20:42:40 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_checker	find_checker(const char *arg);
static int			run_checker(t_checker checker, char *const envp[]);

int	main(int argc, char const **argv, char *const envp[])
{
	t_shell_table	*shell_table;
	t_checker		checker;

	if (argc > 1)
	{
		checker = find_checker(argv[1]);
		if (checker)
			return (run_checker(checker, envp));
	}
	shell_table = build_shell_table(envp);
	if (!shell_table)
		return (1);
	setup_signal_handlers();
	prompt(on_input, shell_table);
	st_destroy(shell_table);
	return (0);
}

static t_checker	find_checker(const char *arg)
{
	static const t_checker_entry	g[] = {
	{"--tokenize", tokenize_checker},
	{"--heredoc", heredoc_checker},
	{"--parse", parse_checker},
	{"--directory", directory_checker},
	{"--path", path_checker},
	{"--builtin", builtin_checker},
	{"--expand", expand_checker},
	{"--remove-quotes", remove_quotes_checker},
	{"--wildcard", wildcard_checker},
	{"--relative-path", relative_path_checker},
	{NULL, NULL}
	};
	int								i;

	i = 0;
	while (g[i].name)
	{
		if (ft_strncmp(arg, g[i].name, ft_strlen(g[i].name) + 1) == 0)
			return (g[i].checker);
		i++;
	}
	return (NULL);
}

static int	run_checker(t_checker checker, char *const envp[])
{
	t_shell_table	*shell_table;

	shell_table = build_shell_table(envp);
	if (!shell_table)
		return (1);
	prompt(checker, shell_table);
	st_destroy(shell_table);
	return (0);
}
