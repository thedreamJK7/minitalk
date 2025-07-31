/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:13:13 by jkubaev           #+#    #+#             */
/*   Updated: 2025/06/06 16:33:21 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	long	z;
	int		count;

	z = n;
	count = 0;
	if (z < 0)
	{
		z *= -1;
		count += ft_putchar('-');
	}
	if (z >= 10)
	{
		count += ft_putnbr(z / 10);
		z %= 10;
	}
	count++;
	ft_putchar(z + 48);
	return (count);
}
