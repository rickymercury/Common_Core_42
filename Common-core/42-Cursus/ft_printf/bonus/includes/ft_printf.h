/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:55:28 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/18 23:07:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

typedef struct s_flags
{
	int	align_left;
	int	plus;
	int	space;
	int	hash;
	int	zero;
	int	width;
	int	precision;
	int	point;
}	t_flags;

// printf
int		ft_printf(const char *format, ...);
void	parse_flags(t_flags *flags, const char *flag, int *i);
int	    print_format(t_flags *flags, const char *type, int *i, va_list args);
// print_c
int		ft_print_c(t_flags *flags, int c);
// print_s
int		ft_print_s(t_flags *flags, char *str);
int		putstr_width(int width, char *str, int align_left);
int		putstr_precision(int precision, char *str);
int		putstr_width_precision(int width, int precision, char *str, int align_left);
// print_p
int		ft_print_p(t_flags *flags, size_t number);
int		print_p_spaces(int spaces, int align_left, size_t number);
int		print_ptr_address(size_t number, char ptr);
int		ptr_len(size_t number);
// print_d
int		ft_print_d(t_flags *flags, long number);
int		print_d_left(long number, int width, int precision, char sign);
int		ft_print_u(size_t number);
int     ft_putnbr(int number); 
int		print_d_precision(long number, int precision, char sign);
int		print_d_zeros(long number, int precision);
int		print_d_width(long number, int width, char padding, char sign);
int		print_d_width_v2(long number, int width, char padding, char sign);
int		numlen(long number);
int		print_d_width_precision(long number, int width, int precision, char sign);
int		print_d_width_precision_v2(long number, int width, int precision, char sign);
// print_x
int		ft_print_x(t_flags *flags, long number, char x);
int     print_hex_address(size_t number, char x);
int     hex_len(size_t number);
int		print_x_left(t_flags *flags, long number, char x);
int		print_x_prec(int prec, long number, char x);
int		print_x_hash(t_flags *flags, long number, char x, char padding);
int		print_x_width(t_flags *flags, long number, char x, char padding);
// printf_utils
size_t  ft_strlen(const char *str); 
int	    ft_putchar(char c);
int	    ft_putstr(char *str);
int	    ft_atoi(const char *str);
int	    ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);

#endif