/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:01:40 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/21 08:42:04 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// The program is designed to send a message (in binary)
// to a server process using signals. The message is sent
// one character at a time and each character is converted
// to binary (7 bits) and then transmitted using SIGUSR1 and SIGUSR2 signals.
// The server process receives the signals and converts
// the bits back to ASCII characters.
// *The variable g_status is used to keep track of whether
// a signal has been received or not.

static int	g_status;
// The function signal_recive is the signal handler for SIGUSR1 and SIGUSR2
//  signals. It sets the value of g_status to 1 when a signal is 
// received and exits the program when a SIGUSR1 signal is received
//  (which indicates that the message has been received successfully).

void	signal_recive(int n)
{
	static int	b;

	g_status = 1;
	if (n == SIGUSR2)
		b++;
	if (n == SIGUSR1)
	{
		ft_printf("Message received successfully: %d\n", b / 8);
		exit(0);
	}
	return ;
}
// The function conversion is used to convert each character
// to binary (8 bits) and transmit it using SIGUSR1 and
// SIGUSR2 signals. It sends each bit one at a time and 
// waits for a response from the server before sending the next bit.

int	conversion(char c, int pid, int i)
{
	int	n;

	while (i >= 0)
	{
		n = 0;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_status == 0)
		{
			usleep(100000);
			n++;
			if (n == 5)
			{
				write(1, "No response from the server\n", 29);
				exit(1);
			}
		}
		g_status = 0;
		i--;
	}
	return (0);
}
// The main function parses the command-line arguments,
// sets up the signal handlers, and calls the conversion
// function to send each character in the message to the
// server process.

int	main(int argc, char *argv[])
{
	int	n;
	int	index;

	if (argc != 3)
	{
		ft_printf("Incorrect number of arguments\n");
		return (1);
	}
	index = 0;
	n = ft_atoi(argv[1]);
	signal(SIGUSR1, signal_recive);
	signal(SIGUSR2, signal_recive);
	while (argv[2][index])
		conversion(argv[2][index++], n, 7);
	conversion(0, n, 7);
	return (0);
}
