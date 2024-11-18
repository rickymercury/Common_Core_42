/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:09:28 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/18 23:23:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(size_t number)
{
	int	count;

	count = 0;
	if (number < 10)
	{
		count++;
		ft_putchar(number + 48);
		return (count);
	}
	count += ft_print_u(number / 10);
	count += ft_print_u(number % 10);
	return (count);
}

int ft_putnbr(int number) 
{
    char    c;
    int count;

    count = 0;
    if (number == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (number < 0)
    {
        count += write(1, "-", 1);
        number = -number;
    }
    if (number >= 10) 
        count += ft_putnbr(number / 10);
    c = (number % 10) + '0';
    count += write(1, &c, 1);
    return (count);
} 

int	print_d_zeros(long number, int precision)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number);
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	while (count < precision - len)
		count += ft_putchar('0');
	count += ft_print_u(number);
	return (count);
}

int	numlen(long number)
{
	int	len;

	len = 1;
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		len++;
		number /= 10;
	}
	return (len);
}

int	print_d_width_v2(long number, int width, char padding, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number + 1);
	if (padding == '0')
	{
		ft_putchar(sign);
		while (count < width - len)
			count += ft_putchar('0');
		return (count + ft_putnbr(number) + 1);
	}
	while (count < width - len)
		count += ft_putchar(' ');
	ft_putchar(sign);
	return (count + ft_putnbr(number) + 1);
}

int	print_d_width_precision_v2(long number, int width, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number);
	if (precision > len)
		len = precision;
	while (count < width - len - 1)
		count += ft_putchar(' ');
	return (count + print_d_precision(number, precision, sign));
}

int	print_d_left(long number, int width, int precision, char sign)
{
	int	count;

	count = 0;
	if (number == 0 && width > 0)
	{
		if (precision != 0)
			count += ft_putchar('0');
		while (count < precision)
			count += ft_putchar('0');
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	count += print_d_precision(number, precision, sign);
	while (count < width)
		count += ft_putchar(' ');
	return (count);
}

int	print_d_precision(long number, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number);
	if (number == 0 && precision == 0)
		return (0);
	if (number < 0)
		return (print_d_zeros(number, precision + 1));
	if (sign == '+' || sign == ' ')
		count += ft_putchar(sign);
	while (count < precision - len)
		count += ft_putchar('0');
	return (count + ft_print_u(number));
}

int	print_d_width(long number, int width, char padding, char sign)
{
	int	len;
	int	count;

	count = 0;
	if (number < 0)
	{
		len = numlen(number);
		if (padding == '0')
			return (print_d_zeros(number, width));
		while (count < width - len - 1)
			count += ft_putchar(' ');
		return (count + ft_putnbr(number));
	}
	if (sign == '+')
		return (print_d_width_v2(number, width, padding, sign));
	len = numlen(number);
	while (count < width - len)
		count += ft_putchar(padding);
	return (count + ft_print_u(number));
}

int	print_d_width_precision(long number, int width, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	if (number < 0)
	{
		len = numlen(number);
		if (precision > len)
			len = precision;
		while (count < width - len - 1)
			count += ft_putchar(' ');
		return (count += print_d_precision(number, precision, sign));
	}
	if (sign == '+' || sign == ' ')
		return (print_d_width_precision_v2(number, width, precision, sign));
	len = numlen(number);
	if (number == 0)
		len = 0;
	if (precision > len)
		len = precision;
	while (count < width - len)
		count += ft_putchar(' ');
	return (count + print_d_precision(number, precision, sign));
}

int	ft_print_d(t_flags *flags, long number)
{
	char	sign;
	char	padding;

	sign = '-';
	padding = ' ';
	if (flags -> space)
		sign = ' ';
	if (flags -> plus)
		sign = '+';
	if (flags -> zero)
		padding = '0';
	if (flags -> align_left)
		return (print_d_left(number, flags->width,
				flags->precision - 1, sign));
	if (flags -> width > 0 && flags -> precision > 0)
		return (print_d_width_precision(number, flags->width, flags->precision - 1, sign));
	if (flags -> width)
		return (print_d_width(number, flags->width, padding, sign));
	if (flags -> precision)
		return (print_d_width_precision(number, flags->width, flags->precision - 1, sign));
	if (number < 0)
		return (ft_putnbr(number));
	if (sign == '+' || sign == ' ')
		return (ft_putchar(sign) + ft_print_u(number));
	return (ft_print_u(number));
}
