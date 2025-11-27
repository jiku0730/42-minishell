/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:04:25 by urassh            #+#    #+#             */
/*   Updated: 2025/11/27 14:54:45 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_input(char *input, t_shell_table *shell_table)
{
	(void)shell_table;
	free(input);
}
