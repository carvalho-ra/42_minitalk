/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:12:50 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:53 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send(int pid, char c);

// Insert the PID of the server in the first argument.
// Insert the message in the second argument.
// The message will be sent one character at a time.
// The server will print the message. Once finished, the client exits.

int	main(int argc, char **argv)
{
	int pid;
	int	index;
	
	//if there's more than 2 arguments ||
	//if the second argument (PID) is not a number ||
	//if there's not a second argument (PID)
	if (argc != 3 || /* !ft_isdigit(argv[1]) || */ !argv[2])
	{
		//print out instructions
		ft_printf("Command: ./client [process ID] [message]\n");
		//return error
		return (1);
	}
	//use ft_atoi to convert char to int
	pid = ft_atoi(argv[1]);
	//set counter to zero
	index = 0;
	//while there's an string 
	while (argv[2][index] != '\0')
	{
		//send a char
		send(pid, argv[2][index++]);
	}
	return 0;
}

//send a character to server, one bit at a time
//kill sends a signal to the process specified in the first argument

void	send(int pid, char c)
{
	int	bit;
	
	//set bit to zero	
	bit = 0;
	//iterate while there's a char (8bits)
	while (bit < 8)
	{
		//if there's a char &
		//the bit is ON 
		if (c & (1 << bit))
		{
			//send signal 2 (1)
			kill(pid, SIGUSR2);
		}
		else
		{
			//send signal 1 (0)
			kill(pid, SIGUSR1);
		}
		//move to the next bit
		bit++;
		//whait half a second for the next send
		usleep(500);
	}
}

