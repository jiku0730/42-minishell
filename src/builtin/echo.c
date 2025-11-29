/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:16:37 by surayama          #+#    #+#             */
/*   Updated: 2025/11/29 18:08:49 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static void	skip_head_node(t_list **argv);
static bool	check_n_option(t_list *argv);
static void	print_argv(t_list *to_print_argv, bool with_newline);

int	echo(t_list *argv, t_shell_table *shell_table)
{
	t_list	*echo_argv;
	bool	use_n_option;
	bool	with_newline;

	(void)shell_table;
	echo_argv = argv;
	with_newline = true;
	skip_head_node(&echo_argv);
	use_n_option = check_n_option(echo_argv);
	if (use_n_option)
	{
		with_newline = false;
		skip_head_node(&echo_argv);
	}
	print_argv(echo_argv, with_newline);
	return (0);
}

static void	skip_head_node(t_list **argv)
{
	if (argv && *argv)
		*argv = (*argv)->next;
}

static bool	check_n_option(t_list *argv)
{
	t_list	*option_node;
	char	*str;
	int		i;

	option_node = argv;
	if (!option_node || !option_node->content)
		return (false);
	str = (char *)option_node->content;
	if (str[0] != '-' || str[1] == '\0')
		return (false);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

static void	print_argv(t_list *to_print_argv, bool with_newline)
{
	t_list	*current;

	current = to_print_argv;
	while (current)
	{
		if (current->content)
		{
			printf("%s", (char *)current->content);
			if (current->next)
				printf(" ");
		}
		current = current->next;
	}
	if (with_newline)
		printf("\n");
}
