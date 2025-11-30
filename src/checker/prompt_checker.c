/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:45:50 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/12/01 01:52:26 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <constants.h>
#include <stdio.h>

/* $>cc ./prompt_checker.c -I../../includes */
int	main(void)
{
	printf("SHELL_NAME = %s\n", SHELL_NAME);
	printf("PROMPT = %s\n", PROMPT);
	return (0);
}
