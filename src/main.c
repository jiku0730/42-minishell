/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:33:28 by urassh            #+#    #+#             */
/*   Updated: 2025/10/01 15:33:36 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void on_input(char *input)
{
    if (input)
        write(STDOUT_FILENO, input, ft_strlen(input));
}

int main(void)
{
    console(on_input);
    return (0);
}
