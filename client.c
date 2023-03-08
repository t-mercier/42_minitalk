/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 20:45:34 by tmercier      #+#    #+#                 */
/*   Updated: 2023/01/05 18:14:10 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"
#include <signal.h>
#include <unistd.h>
#include <limits.h>

/*
 * volatile sig_atomic_t type ensures that the
 * variable is accessed atomically, and that it should
 * not be used to store values that require more than
 * one instruction to access or modify.
 */

static bool	check_args(int ac, char **av)
{
	if ((ac == 3 && !av[2][0]))
		exit_message("Error: Please provide a non-empty "
			"string to send to the server.\n", 1);
	if (ac != 3)
		exit_message("Error Usage : ./client "
			"<pid> <message> \n", 1);
	return (true);
}

static void	sigusr_h(int sig)
{
	static volatile sig_atomic_t	n = 0;

	if (sig == SIGUSR1)
		++n;
	else
	{
		ft_printf("%s%d%s\n", YELLOW, n, RESET);
		exit(0);
	}
}

static void	send_sig(char *str, int pid)
{
	volatile sig_atomic_t	n;
	volatile sig_atomic_t	c;

	while (*str)
	{
		n = 8;
		c = *str++;
		while (n--)
		{
			if (c >> n & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	n = 8;
	while (n--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	check_args(ac, av);
	pid = ft_atoi(av[1]);
	if (!pid || pid < 0 || pid > INT_MAX)
		exit_message("Error: Invalid pid\n", 1);
	ft_printf("%sTotal Bytes Sent     %s| %s%d%s\n",
		CYAN, RESET, CYAN, ft_strlen(av[2]), RESET);
	ft_printf("%sTotal Bytes Received %s| ", YELLOW, RESET);
	signal(SIGUSR1, sigusr_h);
	signal(SIGUSR2, sigusr_h);
	send_sig(av[2], pid);
	send_sig("\n", pid);
	while (1)
		pause();
	return (0);
}
