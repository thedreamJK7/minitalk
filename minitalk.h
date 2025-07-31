/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javokhir <javokhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:00:51 by javokhir          #+#    #+#             */
/*   Updated: 2025/07/31 19:21:28 by javokhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//  Libraries

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

//  Headers

# include "./ft_printf/ft_printf.h"

//  structs

typedef struct s_minitalk
{
	char	c_char;
	int		bits;
}				t_minitalk;

//  Functions

#endif