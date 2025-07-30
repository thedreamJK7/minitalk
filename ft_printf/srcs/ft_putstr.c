/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkubaev <jkubaev@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:02:20 by jkubaev           #+#    #+#             */
/*   Updated: 2025/06/05 15:16:18 by jkubaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_putchar(*s);
		count++;
		s++;
	}
	return (count);
}