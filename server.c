/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 20:49:27 by tmercier      #+#    #+#                 */
/*   Updated: 2023/01/05 18:12:53 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"
#include <signal.h>

/*
 * sig.sa_flags is set to 0 means that
 * no flags are set and the default behavior
 * is used signal handler will be called
 * when the specified signal (in this case,
 * SIGUSR1 or SIGUSR2) is received.
 *
 * sigemptyset -> initializes the signal set
 * pointed to by sig.sa_mask to be the empty set.
 * This means that no signals are blocked when
 * the handler function is executed.
 *
 * volatile sig_atomic_t type ensures that the
 * variable is accessed atomically, and that it should
 * not be used to store values that require more than
 * one instruction to access or modify.
 */

static void	pid(void)
{
	pid_t	pid;

	pid = getpid();
	if (!getpid())
		exit_message("Error: getpid()\n", 1);
	ft_printf("PID [ %s%d%s ]\n", GREEN, getpid(), RESET);
}

static void	sigusr_h(int sig, siginfo_t *info, void *context)
{
	static volatile sig_atomic_t	n = 0;
	static volatile sig_atomic_t	c = 0;
	static pid_t					pid = 0;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++n == 8)
	{
		n = 0;
		if (!c)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pid, SIGUSR1);
	}
	else
		c <<= 1;
}

static void	exec_signal(struct sigaction s)
{
	if (sigaction(SIGUSR1, &s, 0) == -1)
		exit_message("Error: Sigaction exec\n", 1);
	if (sigaction(SIGUSR2, &s, 0) == -1)
		exit_message("Error: Sigaction exec\n", 1);
}

int	main(int ac, char **av)
{
	struct sigaction	s;

	(void)av;
	if (ac != 1)
		exit_message("Error Usage : ./server\n", 1);
	pid();
	s.sa_sigaction = sigusr_h;
	s.sa_flags = SA_SIGINFO;
	exec_signal(s);
	while (1)
		pause();
	return (0);
}
