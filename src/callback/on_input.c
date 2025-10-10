/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:25 by urassh            #+#    #+#             */
/*   Updated: 2025/10/10 17:04:42 by urassh           ###   ########.fr       */
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
