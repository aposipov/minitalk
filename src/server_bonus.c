/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:31:04 by lchristi          #+#    #+#             */
/*   Updated: 2022/01/14 14:31:24 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handle_eot_request(unsigned int *pid)
{
	kill(*pid, SIGUSR2);
	*pid = 0;
}

void	handle_sigs(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static unsigned int		client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return (handle_eot_request(&client_pid));
		ft_putchar(c);
		c = 0;
		kill(client_pid, SIGUSR1);
		usleep(10);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("*bonus part*\n");
	ft_putstr("server is run!\n");
	ft_putstr(" PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = handle_sigs;
	sa.sa_flags = SA_SIGINFO ;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}