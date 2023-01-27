/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:05:54 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/01/27 17:17:51 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

//get the PID of the caling process.

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("PID= %d\n", pid);
}
