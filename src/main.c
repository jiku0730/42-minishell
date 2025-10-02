/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:13:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/09/29 15:17:54 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_input(char *input)
{
	if (!input)
		return ;
	if (ft_strncmp(input, "exit", 4) == 0 && (input[4] == '\0'
			|| ft_isspace(input[4])))
	{
		write(STDOUT_FILENO, "exit\n", 5);
		free(input);
		exit(0);
	}
	write(STDOUT_FILENO, input, ft_strlen(input));
	write(STDOUT_FILENO, "\n", 1);
	free(input);
}

int	main(void)
{
	prompt(on_input);
	return (0);
}
