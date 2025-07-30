/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:40:58 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/30 15:58:55 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		k;
	int		sum;

	i = 0;
	sum = 0;
	k = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		k *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + (nptr[i] - '0');
		i++;
	}
	return (sum * k);
}