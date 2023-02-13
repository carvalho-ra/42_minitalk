/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:05:54 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/02/13 16:53:19 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handler(int signal);

int	main(void)
{
	int	pid;

	//get PID of the calling process (server)
	pid = getpid();
	ft_printf("Server PID = %d\n", pid);
	//start listening for a message
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	//process must stay put so PID doesen´t change
	while (1)
		pause();
	return (0);
}

void	handler(int signal)
{
	static char	c;
	static int	bit;
	
	//if signal is 1
	if (signal == SIGUSR2)
	{
		//change bit to one
		c = c | (1 << 1);
	}
	//next bit
	bit++;
	//if it reaches 8 bits, print the char
	if (bit == 8)
	{
		write (1, &c, 1);
		//turn bit to zero again
		bit = 0;
		//turn char to null
		c = 0;
	}
}
