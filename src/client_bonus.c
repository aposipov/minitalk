/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:30:30 by lchristi          #+#    #+#             */
/*   Updated: 2022/01/14 14:30:53 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	hint(void)
{
	ft_putstr("usage: ./client [pid] [string]\n");
	return (0);
}

static void	handle_eot_response(int sig, siginfo_t *siginfo, void *context)
{
	static int	received = 0;

	(void)siginfo;
	(void)context;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr(received);
		ft_putstr(" byte\n");
		exit(0);
	}
}

static void	send(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep (10);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (hint());
	ft_putstr("client sent    : ");
	ft_putnbr(ft_strlen(argv[2]));
	ft_putstr(" byte\n");
	ft_putstr("server received: ");
	sa.sa_sigaction = handle_eot_response;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	send(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
