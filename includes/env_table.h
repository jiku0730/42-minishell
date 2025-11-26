/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:13:33 by urassh            #+#    #+#             */
/*   Updated: 2025/11/26 16:31:31 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_TABLE_H
# define ENV_TABLE_H

# include <constants.h>
# include <libft.h>

# define ENV_TABLE_INIT_SIZE 256

t_hash_table	*build_env_table(char **envp);
char			**export_envp(t_hash_table *env_table);

#endif
