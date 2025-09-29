/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:16:34 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:00:41 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include "libft.h"
// #include <fcntl.h>    // for open()
// #include <stdio.h>    // for printf()
// #include <unistd.h>   // for close(), read()

// int	main(void)
// {
// 	int		fd;
// 	char	buffer[10];
// 	int		bytes_read;

// 	// Test Case 1: Output character to standard output
// 	printf("Test Case 1: Output character 'A' to standard output: ");
// 	ft_putchar_fd('A', 1);
// 	printf("\n");
// 	// Test Case 2: Output character to standard error
// 	fprintf(stderr, "Test Case 2: Output character 'B' to standard error: ");
// 	ft_putchar_fd('B', 2);
// 	fprintf(stderr, "\n");
// 	// Test Case 3: Output character to a file
// 	printf("Test Case 3: Output character 'C' to a file\n");
// 	fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		printf("Error: Could not open file\n");
// 		return (1);
// 	}
// 	ft_putchar_fd('C', fd);
// 	close(fd);
// 	// Open the file and check its contents
// 	fd = open("test_putchar.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error: Could not read file\n");
// 		return (1);
// 	}
// 	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 	buffer[bytes_read] = '\0';
// 	printf("File contents: %s\n", buffer);
// 	close(fd);
// 	// Test Case 4: Output multiple characters to a file consecutively
// 	printf("Test Case 4: Consecutive output of multiple characters\n");
// 	fd = open("test_multiple.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		ft_putchar_fd('4', fd);
// 		ft_putchar_fd('2', fd);
// 		ft_putchar_fd('T', fd);
// 		ft_putchar_fd('o', fd);
// 		ft_putchar_fd('k', fd);
// 		ft_putchar_fd('y', fd);
// 		ft_putchar_fd('o', fd);
// 		close(fd);
// 		fd = open("test_multiple.txt", O_RDONLY);
// 		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 		buffer[bytes_read] = '\0';
// 		printf("Result of consecutive output: %s\n", buffer);
// 		close(fd);
// 	}
// 	return (0);
// }
