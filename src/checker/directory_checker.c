/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:10:35 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:47:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directory.h"
#include "minishell.h"

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
		printf("exit\n");
		rl_clear_history();
		free(input);
		exit(0);
	}
	test_entries(input);
	test_all_entries(input);
	free(input);
}

static void	test_entries(const char *input)
{
	printf("\n=== Testing list_directory ===\nPath: %s\n", input);
	test_function(input, false, list_directory,
		"\n--- Without hidden files ---\nEntries");
	test_function(input, true, list_directory,
		"\n--- With hidden files ---\nEntries");
}

static void	test_all_entries(const char *input)
{
	printf("\n=== Testing list_directory_recursive ===\nPath: %s\n", input);
	test_function(input, false, list_directory_recursive,
		"\n--- Without hidden files ---\nAll Entries (recursive)");
	test_function(input, true, list_directory_recursive,
		"\n--- With hidden files ---\nAll Entries (recursive)");
}

static void	test_function(const char *input, bool include_hidden,
		int (*func)(const char *, bool, t_list **), const char *title)
{
	t_list		*entries;
	t_list		*tmp;
	int			result;
	const char	*error_msg;

	result = func(input, include_hidden, &entries);
	if (result != SUCCESS)
	{
		error_msg = "Unknown error";
		if (result == NOT_FOUND)
			error_msg = "Directory not found";
		else if (result == NO_PERMISSION)
			error_msg = "Permission denied";
		printf("Error: %s\n", error_msg);
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

	printf("%s:\n", title);
	count = 0;
	current = entries;
	while (current)
	{
		printf("  - %s\n", (char *)current->content);
		current = current->next;
		count++;
	}
	printf("Total: %d entries\n", count);
}
