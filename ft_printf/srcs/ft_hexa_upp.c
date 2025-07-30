/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:59:36 by jkubaev           #+#    #+#             */
/*   Updated: 2025/06/05 17:00:19 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_hexa_upp(unsigned int n)
{
	int	count;
	char *base;

	base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count++;
		ft_hexa_upp(n / 16);
	}
	ft_putchar(base[n % 16]);
	count++;
	return (count);
}