/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:53:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/10 22:39:36 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative(int *number, int *count)
{
	if (*number < 0)
	{
		write(1, "-", 1);
		*number = -*number;
		(*count)++;
	}
}

int	ft_print_d(int n)
{
	int	count;
	int	digits[12];
	int	i;

	count = 0;
	if (n == -2147483648)
		return (ft_print_s("-2147483648"));
	negative(&n, &count);
	if (n == 0)
		return (ft_print_c('0'));
	i = 0;
	while (n != 0)
	{
		digits[i++] = n % 10;
		n = n / 10;
		count++;
	}
	i--;
	while (i >= 0)
		ft_print_c(digits[i--] + '0');
	return (count);
}

/*
> We have conditions for both the MIN_VALUE of int and value 0;

> If the number is negative, we write the character - and convert
the number to positive;

> We than use the itoa method;
	> Storing each of the characters in digits;
		> Using the % 10 and / 10;

> We write the number using the function to print char the values
of digits backwards by adding '+0' to it;
*/