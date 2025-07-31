/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:39 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/31 14:18:56 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (*argv[2])
		{
			i = 8;
			while (i--)
			{
				if ((*argv[2] >> i) & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(500);
			}
			argv[2]++;
		}
		i = 8;
		while (i--)
		{
			kill(pid, SIGUSR2);
			usleep(500);
		}
	}
	else
	{
		ft_printf("Error: More or not enough arguments");
		exit(EXIT_FAILURE);
	}
}

