/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:52:33 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 16:34:39 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int     ft_print_char(char c);
size_t	ft_strlen(const char *str);
int     ft_print_str(char *str);
int     ft_print_num(int n);
int     ft_print_pointer(unsigned long long ptr);
int     ft_print_unsigned(unsigned int n);
int     ft_print_hexadecimal(unsigned int num, const char format);

#endif