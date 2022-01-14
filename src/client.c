/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:00:47 by lchristi          #+#    #+#             */
/*   Updated: 2022/01/11 21:19:57 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	send2s(int pid, char *str)
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
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep (100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) == 0)
		ft_putstr("input PID !");
	if (kill(ft_atoi(argv[1]), SIGUSR2) == -1)
	{
		ft_putstr("Wrong PID!\n");
		exit(EXIT_FAILURE);
	}
	send2s(ft_atoi(argv[1]), argv[2]);
	return (0);
}
