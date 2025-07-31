/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:39 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/31 20:46:21 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(unsigned char bits, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((bits >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Wrong PID");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Wrong PID");
				exit(1);
			}
		}
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	unsigned char	*msg;
	int				pid;

	if (argc != 3)
	{
		ft_printf("I need a correct info");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_printf("PID must be positive");
		exit(1);
	}
	msg = (unsigned char *)argv[2];
	while (*msg)
	{
		send_bit(*msg, pid);
		msg++;
	}
	send_bit('\0', pid);
	return (0);
}
