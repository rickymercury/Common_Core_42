/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:52:33 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/13 13:08:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
#include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

int     ft_printf(const char *format, ...);
int	    ft_print_c(int c);
int	    ft_print_s(const char *str);
int	    ft_print_d(int n);
int     ft_print_p(unsigned long long ptr);
int     ft_print_u(unsigned int n);
int	    ft_print_x(unsigned int x, int upper);

#endif
