/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:10:21 by jkubaev           #+#    #+#             */
/*   Updated: 2025/07/30 15:54:18 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_put_unsigned(unsigned int n);
int	ft_hexa_low(unsigned int n);
int	ft_hexa_upp(unsigned int n);
int	ft_atoi(const char *nptr);

#endif