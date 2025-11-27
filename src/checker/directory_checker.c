/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:10:35 by surayama          #+#    #+#             */
/*   Updated: 2025/11/27 16:42:07 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <directory.h>
#include <minishell.h>

static void	print_entries(t_list *entries, const char *title);
static void	test_function(const char *input, bool include_hidden,
				int (*func)(const char *, bool, t_list **), const char *title);
static void	test_entries(const char *input);
static void	test_all_entries(const char *input);

void	directory_checker(char *input, t_shell_table *shell_table)
{
	(void)shell_table;
	if (ft_strncmp(input, "exit", 5) == 0)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		st_destroy(shell_table);
		exit(0);
	}
	test_entries(input);
	test_all_entries(input);
}

static void	test_entries(const char *input)
{
	ft_putstr_fd("\n=== Testing get_directory_entries ===\n", 1);
	ft_putstr_fd("Path: ", 1);
	ft_putendl_fd(input, 1);
	test_function(input, false, get_directory_entries,
		"\n--- Without hidden files ---\nEntries");
	test_function(input, true, get_directory_entries,
		"\n--- With hidden files ---\nEntries");
}

static void	test_all_entries(const char *input)
{
	ft_putstr_fd("\n=== Testing get_directory_all_entries ===\n", 1);
	ft_putstr_fd("Path: ", 1);
	ft_putendl_fd(input, 1);
	test_function(input, false, get_directory_all_entries,
		"\n--- Without hidden files ---\nAll Entries (recursive)");
	test_function(input, true, get_directory_all_entries,
		"\n--- With hidden files ---\nAll Entries (recursive)");
}

static void	test_function(const char *input, bool include_hidden,
		int (*func)(const char *, bool, t_list **), const char *title)
{
	t_list	*entries;
	t_list	*tmp;
	int		result;

	result = func(input, include_hidden, &entries);
	if (result != SUCCESS)
	{
		ft_putstr_fd("Error: ", 1);
		if (result == NOT_FOUND)
			ft_putendl_fd("Directory not found", 1);
		else if (result == NO_PERMISSION)
			ft_putendl_fd("Permission denied", 1);
		else
			ft_putendl_fd("Unknown error", 1);
		return ;
	}
	print_entries(entries, title);
	while (entries)
	{
		tmp = entries->next;
		free(entries->content);
		free(entries);
		entries = tmp;
	}
}

static void	print_entries(t_list *entries, const char *title)
{
	t_list	*current;
	int		count;

	ft_putstr_fd(title, 1);
	ft_putstr_fd(":\n", 1);
	count = 0;
	current = entries;
	while (current)
	{
		ft_putstr_fd("  - ", 1);
		ft_putendl_fd((char *)current->content, 1);
		current = current->next;
		count++;
	}
	ft_putstr_fd("Total: ", 1);
	ft_putnbr_fd(count, 1);
	ft_putendl_fd(" entries", 1);
}
