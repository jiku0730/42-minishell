/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:29:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:01:16 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return ;
}
// #include "libft.h"
// #include <fcntl.h>    // for open()
// #include <stdio.h>    // for printf()
// #include <unistd.h>   // for close(), read()

// int	main(void)
// {
// 	int		fd;
// 	char	buffer[100];
// 	int		bytes_read;

// 	// Test Case 1: Output string with newline to standard output
// 	printf("Test Case 1: Output string with newline to standard output:\n");
// 	ft_putendl_fd("Hello, World!", 1);
// 	printf("↑ 'Hello, World!' with a newline should appear above\n");
// 	// Test Case 2: Output string with newline to standard error
// 	fprintf(stderr,
// 		"Test Case 2: Output string with newline to standard error:\n");
// 	ft_putendl_fd("Error message", 2);
// 	fprintf(stderr, "↑ 'Error message' with a newline should appear above\n");
// 	// Test Case 3: Output string with newline to a file
// 	printf("Test Case 3: Output string with newline to a file\n");
// 	fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		printf("Error: Could not open file\n");
// 		return (1);
// 	}
// 	ft_putendl_fd("42Tokyo", fd);
// 	close(fd);
// 	// Open the file and check its contents
// 	fd = open("test_putendl.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error: Could not read file\n");
// 		return (1);
// 	}
// 	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 	buffer[bytes_read] = '\0';
// 	printf("File contents: ");
// 	for (int i = 0; i < bytes_read; i++)
// 	{
// 		if (buffer[i] == '\n')
// 			printf("\\n");
// 		else
// 			printf("%c", buffer[i]);
// 	}
// 	printf("\n");
// 	close(fd);
// 	// Test Case 4: Empty string
// 	printf("Test Case 4: Output an empty string (only newline)\n");
// 	fd = open("test_empty_endl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		ft_putendl_fd("", fd);
// 		close(fd);
// 		fd = open("test_empty_endl.txt", O_RDONLY);
// 		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 		buffer[bytes_read] = '\0';
// 		printf("Result of empty string (only newline): ");
// 		for (int i = 0; i < bytes_read; i++)
// 		{
// 			if (buffer[i] == '\n')
// 				printf("\\n");
// 			else
// 				printf("%c", buffer[i]);
// 		}
// 		printf("\n");
// 		close(fd);
// 	}
// 	// Test Case 5: NULL pointer
// 	printf("Test Case 5: NULL pointer (confirming no crash)\n");
// 	ft_putendl_fd(NULL, 1);
// 	printf("NULL test complete\n");
// 	return (0);
// }
