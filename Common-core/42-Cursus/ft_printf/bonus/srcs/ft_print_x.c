/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:47:36 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/18 23:24:50 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(size_t number)
{
	int	i;

	i = 0;
	if (number < 16)
		return (i += 1);
	i += hex_len(number / 16);
	i += hex_len(number % 16);
	return (i);
}

int	print_hex_adress(size_t number, char x)
{
	int	printed;

	printed = 0;
	if (number < 16)
	{
		if (x == 'x')
			return (printed += ft_putchar("0123456789abcdef"[number]));
		else if (x == 'X')
			return (printed += ft_putchar("0123456789ABCDEF"[number]));
		return (printed);
	}
	printed += print_ptr_address(number / 16, x);
	printed += print_ptr_address(number % 16, x);
	return (printed);
}

int	print_x_precision(int precision, long number, char x)
{
	int	count;

	if (number == 0 && precision == 0)
		return (0);
	count = hex_len(number);
	while (count < precision)
		count += ft_putchar('0');
	print_hex_adress(number, x);
	return (count);
}

int	print_x_left(t_flags *flags, long number, char x)
{
	int	count;

	count = 0;
	if (flags -> hash)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(x);
	}
	count += print_x_precision(flags -> precision - 1, number, x);
	while (count < flags -> width)
		count += ft_putchar(' ');
	return (count);
}

int	print_x_hash(t_flags *flags, long number, char x, char padding)
{
	int	count;
	int	len;

	count = 0;
	len = hex_len(number);
	if (flags -> precision - 1 - len)
		len = flags -> precision - 1;
	if (padding == 0)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(x);
		while (count < flags -> width - len)
			count += ft_putchar(padding);
		count += print_x_precision(flags -> precision - 1, number, x);
		return (count);
	}
	while (count < flags -> width - 2 - len)
		count += ft_putchar(padding);
	if (number != 0)
		count += ft_putchar('0') + ft_putchar(x);
	count += print_x_precision(flags -> precision - 1, number, x);
	return (count);
}

int	print_x_width(t_flags *flags, long number, char x, char padding)
{
	int	count;
	int	len;

	count = 0;
	len = hex_len(number);
	if (flags -> precision - 1 > len)
		len = flags -> precision - 1;
	if (number == 0 && flags -> precision == 1)
		len = 0;
	while (count < flags -> width - len)
		count += ft_putchar(padding);
	count += print_x_precision(flags -> precision - 1, number, x);
	return (count);
}

int	ft_print_x(t_flags *flags, long number, char x)
{
	char	padding;
	int		len;

	padding = ' ';
	if (flags -> zero)
		padding = '0';
	if (flags -> width && flags -> precision)
		padding = ' ';
	if (flags -> align_left)
		return (print_x_left(flags, number, x));
	if (flags -> hash)
		return (print_x_hash(flags, number, x, padding));
	if (flags -> width)
		return (print_x_width(flags, number, x, padding));
	if (flags -> precision)
		return (print_x_precision(flags -> precision - 1, number, x));
	len = hex_len(number);
	print_hex_adress(number, x);
	return (len);
}