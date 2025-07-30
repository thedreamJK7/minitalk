/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:03:07 by jkubaev           #+#    #+#             */
/*   Updated: 2025/06/05 21:46:56 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_hexa_low(unsigned int n)
{
	int	count;
	char *base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count++;
		ft_hexa_low(n / 16);
	}
	ft_putchar(base[n % 16]);
	count++;
	return (count);
}