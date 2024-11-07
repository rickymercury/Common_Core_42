/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:52:33 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 16:29:39 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int     ft_print_c(int c);
int	    ft_print_s(char *str);
int	    ft_print_d(int n);
int     ft_print_p(unsigned long long ptr);
int     ft_print_u(unsigned int n);
int     ft_print_x(unsigned int num, const char hex_format);

#endif
