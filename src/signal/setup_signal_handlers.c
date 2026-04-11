/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signal_handlers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:00:00 by surayama          #+#    #+#             */
/*   Updated: 2026/04/06 00:00:00 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"
#include <readline/readline.h>
#include <termios.h>
#include <unistd.h>

volatile sig_atomic_t	g_signal;

static void	sigint_handler(int sig)
{
	g_signal = sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	disable_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	disable_echoctl();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sigint_handler;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}
