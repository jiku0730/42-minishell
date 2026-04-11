/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:55:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/04/11 17:55:34 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	exit_numeric_error(const char *str)
{
	ft_putstr_fd(SHELL_NAME ": exit: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	exit(2);
}

int	builtin_exit(t_list *argv, t_shell_table *shell_table)
{
	t_list	*args;
	char	*str;

	write(STDOUT_FILENO, "exit\n", 5);
	args = argv->next;
	if (!args)
	{
		str = st_search(shell_table, "?");
		if (!str)
			exit(0);
		exit(ft_atoi(str) & 0xFF);
	}
	if (args->next)
	{
		ft_putstr_fd(SHELL_NAME ": exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	str = (char *)args->content;
	if (!is_numeric(str))
		exit_numeric_error(str);
	exit(ft_atoi(str) & 0xFF);
}
