/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:33:28 by urassh            #+#    #+#             */
/*   Updated: 2025/10/01 16:48:53 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	on_input(char *input)
{
	if (!input)
		return (0);
	if (ft_strncmp(input, "exit", 4) == 0 && (input[4] == '\0'
			|| ft_isspace(input[4])))
	{
		write(STDOUT_FILENO, "exit", 4);
		return (0);
	}
	write(STDOUT_FILENO, input, ft_strlen(input));
	return (1);
}

int	main(void)
{
	prompt(on_input);
	return (0);
}
