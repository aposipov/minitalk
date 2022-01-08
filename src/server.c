/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:33:41 by lchristi          #+#    #+#             */
/*   Updated: 2022/01/07 21:12:06 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int main()
{
	//struct sigaction	sa;

	//reset_data();
	
	ft_putstr("server is run\nPID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	//sa.sa_flags = SA_SIGINFO;
	//
	//
	while (1)
		sleep(1);
}
