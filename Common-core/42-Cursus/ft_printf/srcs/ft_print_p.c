/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:50:30 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 20:26:29 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		count++;
		ptr = ptr / 16;
	}
	return (count);
}

int	ft_recursive_print_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_recursive_print_ptr(ptr / 16);
		ft_recursive_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_print_c(ptr + 48);
		else
			ft_print_c(ptr - 10 + 'a');
	}
	return (ft_count_ptr(ptr));
}

int	ft_print_p(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len = write (1, "0x", 2);
	len += ft_recursive_print_ptr(ptr);
	return (len);
}