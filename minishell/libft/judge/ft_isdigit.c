/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:20:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/05/04 21:53:07 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ASCII only */
int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

// #include <stdio.h>
// #include <time.h>

// int	ft_isdigit_uc(int c)
// {
// 	unsigned char	uc;

// 	uc = (unsigned char)c;
// 	return ('0' <= uc && uc <= '9');
// }

// int ft_isdigit_bit(int c)
// {
// 	return ((unsigned)c - '0' < 10);
// }

// int ft_isdigit_bit_u(int c)
// {
// 	return ((unsigned char)c - '0' < 10);
// }

// int main(void)
// {
// 	for (int i = -5; i <= 130; i++)
// 	{
// 		char *str = (ft_isdigit_uc(i) == 1) ? "OKKKKK" : "NG";
// 		printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	}
// 	for (int i = -5; i <= 130; i++)
// 	{
// 		char *str = (ft_isdigit_bit(i) == 1) ? "OKKKKK" : "NG";
// 		printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	}
// 	for (int i = -5; i <= 130; i++)
// 	{
// 		char *str = (ft_isdigit_bit_u(i) == 1) ? "OKKKKK" : "NG";
// 		printf("%3i, %4c : %2s\n", i,(char)i, str);
// 	}
// 	return (0);
// }

// #define ITERATIONS 1000000000 // billion times loop

// void	benchmark(const char *name, int (*func)(int))
// {
// 	int	result;

// 	clock_t start, end;
// 	result = 0;
// 	start = clock();
// 	for (int i = 0; i < ITERATIONS; i++)
// 	{
// 		result += func(i % 256); // loop to 256
// 	}
// 	end = clock();
// 	printf("%s: %f seconds\n", name, (double)(end - start) / CLOCKS_PER_SEC);
// }

// int	main(void)
// {
// 	printf("Benchmarking isdigit implementations...\n");
// 	benchmark("ft_isdigit_uc", ft_isdigit_uc);
// 	benchmark("ft_isdigit_bit", ft_isdigit_bit);
// 	benchmark("ft_isdigit_bit_u", ft_isdigit_bit_u);
// 	return (0);
// }
