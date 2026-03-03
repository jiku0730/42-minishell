/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/03/03 18:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

static bool	is_tilde_prefix(const char *token);
static char	*expand_tilde_token(const char *token, t_shell_table *table);

t_list	*expand_tilde(t_list *tokens, t_shell_table *shell_table)
{
	t_list	*current;
	char	*expanded;
	char	*old;

	current = tokens;
	while (current)
	{
		if (current->content && is_tilde_prefix(current->content))
		{
			expanded = expand_tilde_token(current->content, shell_table);
			if (expanded)
			{
				old = current->content;
				current->content = expanded;
				free(old);
			}
		}
		current = current->next;
	}
	return (tokens);
}

static bool	is_tilde_prefix(const char *token)
{
	if (token[0] != '~')
		return (false);
	return (token[1] == '\0' || token[1] == '/');
}

static char	*expand_tilde_token(const char *token, t_shell_table *table)
{
	char	*home;

	home = st_search(table, "HOME");
	if (!home)
		return (NULL);
	if (token[1] == '\0')
		return (ft_strdup(home));
	return (ft_strjoin(home, token + 1));
}
