/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:48 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/30 12:26:59 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_arrived(int signum)
{
	if (signum == SIGINT)
	{
		printf("Received SIGINT!\n");
		printf("haiku_category: japanese\n");
	}
	if (signum == SIGQUIT){
		printf("Received SIGQUIT!\n");
		printf("haiku_category: western\n");
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	printf("PID = %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &signal_arrived;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	while (1)
		pause();
	return (0);
}
