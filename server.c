/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:51:36 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/21 08:46:13 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Ignore the third argument, since we are not using it
// If this is the first signal we receive, store the process ID of the client
// If the signal is SIGUSR1, shift the value of c one bit to the left and
//  add 1 to the least significant bit
// If the signal is SIGUSR2, shift the value of c one bit to the left
// If we have read 8 bits, we have a complete character
// Reset the counter i to 0
// If c is 0, we have reached the end of the message and we should send
//  a SIGUSR1 signal to the client
// Otherwise, print the decoded character to the console and reset
//  the value of c
// Send a SIGUSR2 signal to the client to indicate that we are
//  ready for the next bit
void	serverinfo(int n, siginfo_t *info, void *ucontext)
{
	static char	index;
	static int	pid;
	static char	ch;

	(void)ucontext;
	if (pid == 0)
		pid = info->si_pid;
	if (n == SIGUSR1)
		ch = (ch << 1) | 1;
	else if (n == SIGUSR2)
		ch <<= 1;
	if (++index == 8)
	{
		index = 0;
		if (!ch)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		write(1, &ch, 1);
		ch = 0;
	}
	kill(pid, SIGUSR2);
	return ;
}
// Set up the serverinfo() function as the signal
//  handler for SIGUSR1 and SIGUSR2 signals
// Print the process ID of the current process
// Set up signal handlers for SIGUSR1 and SIGUSR2 signals
// Wait indefinitely for signals to be received

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = serverinfo;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
