/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:48 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/30 16:06:47 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_arrived(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("%i\n", SIGUSR1);
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("%i\n", SIGUSR2);
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
	sigaction(SIGINT, &sa, NULL);
	while (1)
		pause();
	return (0);
}
