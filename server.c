/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:48 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/31 20:56:52 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_minitalk	g_msg = {0, 0};

void	signal_arrived(int signum)
{
	if (signum == SIGUSR1)
		g_msg.c_char |= (1 << (7 - g_msg.bits));
	else if (signum == SIGUSR2)
		g_msg.c_char |= (0 >> (7 - g_msg.bits));
	g_msg.bits++;
	if (g_msg.bits == 8)
	{
		ft_printf("%c", g_msg.c_char);
		if (!g_msg.c_char)
			ft_printf("\n");
		g_msg.c_char = 0;
		g_msg.bits = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("PID = %d\n", pid);
	signal(SIGUSR1, signal_arrived);
	signal(SIGUSR2, signal_arrived);
	while (1)
		pause();
}
