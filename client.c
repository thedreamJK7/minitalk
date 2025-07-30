/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:39 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/30 12:37:35 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[]){
	if (argc == 2)
	{
		int random_int;

		for(int i=0; i<100; i++)
		{
			random_int = rand()%2;
			printf("random_int: %d\n",random_int);
			if (random_int == 0)
				kill(atol(argv[1]), SIGINT);
			else
				kill(atol(argv[1]), SIGQUIT);
		}
	}
}
