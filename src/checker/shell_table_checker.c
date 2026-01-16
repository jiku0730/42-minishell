/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_table_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:53:40 by surayama          #+#    #+#             */
/*   Updated: 2026/01/16 13:59:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

static void	print_shell_table_entries(t_shell_table *shell_table);
static void	print_exported_envp(t_shell_table *shell_table);
static void	test_execve_with_envp(t_shell_table *shell_table);

void	shell_table_checker(t_shell_table *shell_table)
{
	printf("\n========== ENV TABLE ENTRIES ==========\n");
	print_shell_table_entries(shell_table);
	printf("\n========== EXPORTED ENVP ==========\n");
	print_exported_envp(shell_table);
	printf("\n========== EXECVE TEST ==========\n");
	test_execve_with_envp(shell_table);
	printf("=======================================\n\n");
}

static void	print_shell_table_entries(t_shell_table *shell_table)
{
	size_t			i;
	t_shell_node	*node;

	if (!shell_table)
	{
		printf("shell_table is NULL\n");
		return ;
	}
	printf("Total entries: %zu\n", shell_table->n_nodes);
	printf("Table size: %zu\n\n", shell_table->size);
	i = 0;
	while (i < shell_table->size)
	{
		node = shell_table->buckets[i];
		while (node)
		{
			printf("[%zu] %s = %s\n", i, node->key, node->value);
			node = node->next;
		}
		i++;
	}
}

static void	print_exported_envp(t_shell_table *shell_table)
{
	char	**envp;
	size_t	i;

	if (!shell_table)
	{
		printf("shell_table is NULL\n");
		return ;
	}
	envp = export_envp(shell_table);
	if (!envp)
	{
		printf("Failed to export envp\n");
		return ;
	}
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		free(envp[i]);
		i++;
	}
	free(envp);
}

static void	free_envp(char **envp)
{
	char	**tmp;

	tmp = envp;
	while (*tmp)
		free(*tmp++);
	free(envp);
}

static void	test_execve_with_envp(t_shell_table *shell_table)
{
	char	**envp;
	pid_t	pid;
	int		status;
	char	*argv[2];

	envp = export_envp(shell_table);
	if (!shell_table || !envp)
	{
		printf("shell_table is NULL or failed to export envp\n");
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		argv[0] = "/usr/bin/env";
		argv[1] = NULL;
		execve("/usr/bin/env", argv, envp);
		perror("execve failed");
		exit(1);
	}
	else if (pid > 0 && waitpid(pid, &status, 0) != -1 && WIFEXITED(status))
		printf("execve test completed!!\n");
	else
		printf("\nFork failed or test terminated abnormally\n");
	free_envp(envp);
}
