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

static long long	ft_atoll_check(const char *str, bool *ovf)
{
	long long	num;
	int			sign;
	int			digit;

	*ovf = false;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = 0;
	while (ft_isdigit((unsigned char)*str))
	{
		digit = *str - '0';
		if (sign == 1 && num > (LLONG_MAX - digit) / 10)
			return (*ovf = true, 0);
		if (sign == -1 && num > -(LLONG_MIN + digit) / 10)
			return (*ovf = true, 0);
		num = num * 10 + digit;
		str++;
	}
	return (num * sign);
}

static void	exit_no_args(t_shell_table *shell_table)
{
	char	*str;

	str = st_search(shell_table, "?");
	if (!str)
		exit(0);
	exit(ft_atoi(str) & 0xFF);
}

int	builtin_exit(t_list *argv, t_shell_table *shell_table)
{
	t_list		*args;
	char		*str;
	long long	val;
	bool		ovf;

	write(STDOUT_FILENO, "exit\n", 5);
	args = argv->next;
	if (!args)
		exit_no_args(shell_table);
	str = (char *)args->content;
	if (!is_numeric(str))
		exit_numeric_error(str);
	if (args->next)
	{
		ft_putstr_fd(SHELL_NAME ": exit: too many arguments\n",
			STDERR_FILENO);
		return (1);
	}
	val = ft_atoll_check(str, &ovf);
	if (ovf)
		exit_numeric_error(str);
	exit((unsigned char)val);
}
