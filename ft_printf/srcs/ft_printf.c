/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:45:48 by jkubaev           #+#    #+#             */
/*   Updated: 2025/07/31 20:25:32 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	my_main_helper(const char **format, int *total, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	va_start(args, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			my_main_helper(&format, &total, args);
		}
		else
		{
			ft_putchar(*format);
			total++;
		}
		format++;
	}
	va_end(args);
	return (total);
}

static void	my_main_helper(const char **format, int *total, va_list args)
{
	if (**format == 'd' || **format == 'i')
		*total += ft_putnbr(va_arg(args, int));
	if (**format == 'c')
		*total += ft_putchar((char)va_arg(args, int));
	if (**format == 's')
		*total += ft_putstr(va_arg(args, char *));
	if (**format == 'u')
		*total += ft_put_unsigned(va_arg(args, unsigned int));
	if (**format == '%')
		*total += ft_putchar('%');
	if (**format == 'x')
		*total += ft_hexa_low(va_arg(args, unsigned int));
	if (**format == 'X')
		*total += ft_hexa_upp(va_arg(args, unsigned int));
	if (**format == 'p')
		*total += ft_putptr(va_arg(args, void *));
}
