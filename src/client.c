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

int main(int argc, char **argv)
{
	int	pid;
	char *str;
	int i;

	if (argc < 3)
	{
		write(1, "check arguments", 15);
		exit(-1);
	}
	pid = atoi(argv[1]); //atoi
	str = argv[2];
	while(*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		str++;
	}
	return (0);
}
