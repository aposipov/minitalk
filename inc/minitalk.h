/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:41:21 by lchristi          #+#    #+#             */
/*   Updated: 2022/01/07 20:21:21 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

//typedef struct s_data
//{
//	int		i;
//	char	c;
//	int		client_pid;
//}	t_data;

void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);

#endif
