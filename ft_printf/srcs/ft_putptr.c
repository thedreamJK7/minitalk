/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:21:48 by jkubaev           #+#    #+#             */
/*   Updated: 2025/06/06 17:15:21 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	int					count;
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	if (!addr)
		return (write(1, "(nil)", 5));
	count = 0;
	count += ft_putstr("0x");
	count += ft_hexa_low_ptr(addr);
	return (count);
}
