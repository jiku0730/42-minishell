/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:35:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/01 15:48:20 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

static char *read_line(void);

int console(int (*handler)(char *input))
{
    char *input;
    int should_continue;
    
    while (1)
    {
        write(STDOUT_FILENO, PROMPT, ft_strlen(PROMPT));
        input = read_line();
        if (!input)
            break;
        should_continue = 1;
        if (handler)
            should_continue = handler(input);
        write(STDOUT_FILENO, "\n", 1);
        free(input);
        input = NULL;
        if (!should_continue)
            break;
    }
    return (0);
}

static char *read_line(void)
{
    char    *buffer;
    char    *line;
    ssize_t bytes_read;

    buffer = malloc(CONSOLE_BUFFER_SIZE);
    if (!buffer)
        return (NULL);
    bytes_read = read(STDIN_FILENO, buffer, CONSOLE_BUFFER_SIZE - 1);
    if (bytes_read <= 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[bytes_read] = '\0';
    if (buffer[bytes_read - 1] == '\n')
        buffer[bytes_read - 1] = '\0';
    line = ft_strdup(buffer);
    free(buffer);
    return (line);
}
