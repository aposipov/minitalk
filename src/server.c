/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:33:41 by lchristi          #+#    #+#             */
/*   Updated: 2022/01/11 21:53:16 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	handler_s(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;

	(void)siginfo;
	(void)context;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		ft_putchar(c);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("*mandatory part*\n");
	ft_putstr(" server is run!\n");
	ft_putstr(" PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = handler_s;
	sa.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		ft_putstr("sigaction error\n");
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		ft_putstr("sigaction error\n");
	while (1)
		pause();
	return (0);
}
