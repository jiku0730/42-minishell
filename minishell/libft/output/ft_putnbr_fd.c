/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:33:56 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/05 18:12:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11), (void)0);
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &(char){n % 10 + '0'}, 1);
}

// int	main(void)
// {
// 	int number_set[] = {0, 42, -42, 123, 2147483647, -2147483648};
// 	int fd = 1;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		ft_putnbr_fd(number_set[i], fd);
// 		write(fd, "\n", 1);
// 	}
// 	return (0);
// }

// /* == tester == */
// #include <assert.h>
// #include <errno.h>
// #include <fcntl.h>
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #include <unistd.h>

// void		ft_putnbr_fd(int n, int fd);

// static void	test_ft_putnbr_fd_basic(void)
// {
// 	int		fd;
// 	char	buf[256] = {0};

// 	fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	assert(fd != -1);
// 	ft_putnbr_fd(2, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(42, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(-42, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(2147483647, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(-2147483648, fd);
// 	write(fd, "\n", 1);
// 	close(fd);
// 	fd = open("test_output.txt", O_RDONLY);
// 	assert(fd != -1);
// 	read(fd, buf, sizeof(buf) - 1);
// 	close(fd);
// 	assert(!strcmp(buf, "2\n42\n-42\n2147483647\n-2147483648\n"));
// 	printf("Basic tests passed.\n");
// }

// static void	test_ft_putnbr_fd_invalid_fd(void)
// {
// 	errno = 0;
// 	ft_putnbr_fd(123, -1);
// 	assert(errno != 0);
// 	printf("Invalid fd test passed.\n");
// }

// static void	test_ft_putnbr_fd_stderr(void)
// {
// 	ft_putnbr_fd(42, 2); // should print to stderr
// 	printf("Stderr test ran (check manually).\n");
// }

// static int	check_output_file(int n)
// {
// 	char	expected[32];
// 	char	buf[64] = {0};
// 	int		fd;
// 	char	*newline;

// 	snprintf(expected, sizeof(expected), "%d", n);
// 	fd = open("test_output.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	read(fd, buf, sizeof(buf) - 1);
// 	close(fd);
// 	// remove trailing newline if any
// 	newline = strchr(buf, '\n');
// 	if (newline)
// 		*newline = '\0';
// 	return (strcmp(buf, expected) == 0);
// }

// static void	test_ft_putnbr_fd_random(void)
// {
// 	int	success_count;
// 	int	n;
// 	int	fd;

// 	srand((unsigned int)time(NULL));
// 	success_count = 0;
// 	for (int i = 1; i <= 200; i++)
// 	{
// 		n = (rand() % (INT_MAX)) - (rand() % (INT_MAX));
// 		fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (fd == -1)
// 		{
// 			perror("open");
// 			continue ;
// 		}
// 		ft_putnbr_fd(n, fd);
// 		write(fd, "\n", 1);
// 		close(fd);
// 		if (check_output_file(n))
// 		{
// 			printf("%3d : %11d : Good\n", i, n);
// 			success_count++;
// 		}
// 		else
// 		{
// 			printf("%3d : %11d : NG\n", i, n);
// 		}
// 	}
// 	unlink("test_output.txt");
// 	printf("Random tests passed %d / 200.\n", success_count);
// }

// int	main(void)
// {
// 	test_ft_putnbr_fd_basic();
// 	test_ft_putnbr_fd_invalid_fd();
// 	test_ft_putnbr_fd_stderr();
// 	test_ft_putnbr_fd_random();
// 	return (0);
// }
