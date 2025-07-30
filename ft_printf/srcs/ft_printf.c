/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:45:48 by jkubaev           #+#    #+#             */
/*   Updated: 2025/07/30 15:50:49 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int		total;

	total = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
				total += ft_putnbr((int)va_arg(args, int));
			if (*format == 'c')
				total += ft_putchar((char)va_arg(args, int));
			if (*format == 's')
				total += ft_putstr((char *)va_arg(args, char *));
			if (*format == 'u')
				total += ft_put_unsigned((unsigned int)\
				va_arg(args, unsigned int));
			if (*format == '%')
				total += ft_putchar('%');
			if (*format == 'x')
				total += ft_hexa_low((unsigned int)va_arg(args, unsigned int));
			if (*format == 'X')
				total += ft_hexa_upp((unsigned int)va_arg(args, unsigned int));
		}
		else
			ft_putchar(*format);
		format++;
		total++;
	}
	va_end(args);
	return (total);
}
