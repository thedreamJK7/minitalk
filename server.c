/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:48 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/31 14:18:42 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int  bit_index = 0;
static int word_idx = 0;
static char current_char = 0;
static char message[1000];

void	signal_arrived(int signum)
{
	if (signum == SIGUSR1)
		current_char |= (1 << (7 - bit_index));

	bit_index++;
	if (bit_index == 8)
	{
		message[word_idx] = current_char;
		word_idx++;
		if (current_char == '\0')
		{
			ft_printf("Message: %s\n", message);
			word_idx = 0;
			message[1000] = '\0';
		}
		current_char = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	printf("PID = %d\n", pid);
	sa.sa_flags = 0;
	sa.sa_handler = &signal_arrived;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
