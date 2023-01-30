/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:05:54 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/01/30 10:12:12 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handler(int signal);

int	main(void)
{
	int	pid;

	//get PID of the calling process (server)
	pid = getpid();
	ft_printf("PID= %d\n", pid);
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
	static char	character;
	static int	bit;

	if (signal == SIGUSR2)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write (1, &character, 1);
		bit = 0;
		charcater = 0;
	}
}
