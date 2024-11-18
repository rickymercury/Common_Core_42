/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:45:37 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/18 23:22:28 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_flags *flags, int c)
{
	int	count;

	count = 0;
	if (flags -> align_left == TRUE)
	{
		count += ft_putchar(c);
		flags -> width -= 1;
		while (flags -> width > 0)
		{
			count += ft_putchar(' ');
			flags -> width -= 1;
		}
		return (count);
	}
	while (flags -> width > 1)
	{
		count += ft_putchar(' ');
		flags -> width -= 1;
	}
	count += ft_putchar(c);
	return (count);
}