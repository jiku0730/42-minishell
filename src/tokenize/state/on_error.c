/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:35:00 by surayama          #+#    #+#             */
/*   Updated: 2026/02/05 00:00:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize_private.h"

t_list	*on_error(t_token_store *store, char *input)
{
	if (input)
		free(input);
	free_store(store);
	return (NULL);
}
