/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:08:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/11/27 16:33:51 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **arr)
{
	char	**temp;

	if (!arr)
		return ;
	temp = arr;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(arr);
}
