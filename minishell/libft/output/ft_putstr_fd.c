/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:23:51 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 22:02:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	return ;
}

// #include "libft.h"
// #include <fcntl.h> // for open()
// #include <stdio.h> // for printf()
// #include <unistd.h> // for close(), read()

// int	main(void)
// {
// 	int		fd;
// 	char	buffer[100];
// 	int		bytes_read;

// 	// Test Case 1: Output string to standard output
// 	printf("Test Case 1: Output string to standard output: ");
// 	ft_putstr_fd("Hello, World!", 1);
// 	printf("\n");
// 	// Test Case 2: Output string to standard error
// 	fprintf(stderr, "Test Case 2: Output string to standard error: ");
// 	ft_putstr_fd("Error message", 2);
// 	fprintf(stderr, "\n");
// 	// Test Case 3: Output string to a file
// 	printf("Test Case 3: Output string to a file\n");
// 	fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		printf("Error: Could not open file\n");
// 		return (1);
// 	}
// 	ft_putstr_fd("42Tokyo", fd);
// 	close(fd);
// 	// Open the file and check its contents
// 	fd = open("test_putstr.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error: Could not read file\n");
// 		return (1);
// 	}
// 	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 	buffer[bytes_read] = '\0';
// 	printf("File contents: %s\n", buffer);
// 	close(fd);
// 	// Test Case 4: Empty string
// 	printf("Test Case 4: Output empty string\n");
// 	fd = open("test_empty.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		ft_putstr_fd("", fd);
// 		close(fd);
// 		fd = open("test_empty.txt", O_RDONLY);
// 		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
// 		buffer[bytes_read] = '\0';
// 		printf("Result of empty string: \"%s\"\n", buffer);
// 		close(fd);
// 	}
// 	// Test Case 5: NULL pointer
// 	printf("Test Case 5: NULL pointer (check no crash occurs)\n");
// 	ft_putstr_fd(NULL, 1);
// 	printf("NULL test complete\n");
// 	return (0);
// }
