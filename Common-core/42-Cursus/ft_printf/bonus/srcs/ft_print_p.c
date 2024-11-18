/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:26:59 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/18 23:23:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(size_t number)
{
	int	i;

	i = 0;
	if (number < 16)
		return (i += 1);
	i += ptr_len(number / 16);
	i += ptr_len(number % 16);
	return (i);
}

int	print_ptr_address(size_t number, char ptr)
{
	int	printed;

	printed = 0;
	if (number < 16)
	{
		if (ptr == 'x')
			return (printed += ft_putchar("0123456789abcdef"[number]));
		else if (ptr == 'X')
			return (printed += ft_putchar("0123456789ABCDEF"[number]));
		return (printed);
	}
	printed += print_ptr_address(number / 16, ptr);
	printed += print_ptr_address(number % 16, ptr);
	return (printed);
}

int	print_p_spaces(int width, int align_left, size_t number)
{
	int	string_len;

	string_len = ptr_len(number) + 2;
	if (width <= string_len)
	{
		ft_putstr("0x");
		print_ptr_address(number, 'x');
		return (string_len);
	}
	if (align_left)
	{
		ft_putstr("0x");
		print_ptr_address(number, 'x');
		while (width > string_len)
			string_len += ft_putchar(' ');
		return (string_len);
	}
	while (string_len < width)
		string_len += ft_putchar(' ');
	ft_putstr("0x");
	print_ptr_address(number, 'x');
	return (string_len);
}

int	ft_print_p(t_flags *flags, size_t number)
{
	int	string_len;

	string_len = 0;
	if (number == 0)
	{
		string_len = 5;
		if (flags -> width <= 5)
			return (ft_putstr("(nil)"));
		if (flags -> align_left)
		{
			ft_putstr("(nil)");
			while (string_len < flags -> width)
				string_len += ft_putchar(' ');
			return (string_len);
		}
		while (flags -> width > string_len)
			string_len += ft_putchar(' ');
		ft_putstr("(nil)");
		return (string_len);
	}
	if (flags -> width > 0)
		return (print_p_spaces(flags -> width, flags -> align_left, number));
	string_len += ft_putstr("0x");
	string_len += print_ptr_address(number, 'x');
	return (string_len);
}