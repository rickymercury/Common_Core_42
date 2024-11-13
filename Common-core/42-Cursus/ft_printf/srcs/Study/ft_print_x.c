/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:27:35 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/13 08:58:47 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_lowercase(char a)
{
	if (a >= 'a' && a <= 'f')
		return (1);
	return (0);
}

static void	add_hex(unsigned int x)
{
	char	*hex;
	int		tmp;

	hex = "0123456789abcdef";
	if (!ft_isdigit(hex[x % 16]) && is_lowercase(hex[x % 16]))
	{
		tmp = hex[x % 16] - 32;
		write(1, &tmp, 1);
	}
	else
		write(1, &hex[x % 16], 1);
}

int	ft_print_x(unsigned int x, int upper)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (x >= 16)
		count += ft_print_x(x / 16, upper);
	if (upper)
		add_hex(x);
	else
		write(1, &hex[x % 16], 1);
	count++;
	return (count);
}



/*
void get_hex(unsigned int value, char *result, int *i)
{
    unsigned int remainder;
    char *hex = "0123456789ABCDEF";

    while (value != 0)
    {
        remainder = value % 16;
        result[(*i)--] = hex[remainder];
        value /= 16;
    }
}

int	ft_print_upper_x(unsigned int value)
{
	int				i;
	int				counter;
	char			result[9];

	counter = 0;
	i = 7;
	result[8] = '\0';
	if (value == 0)
	{
		result[i] = '0';
		counter += ft_print_c(result[i]);
	}
    get_hex(value, result, &i);
	i++;
	while (i < 8)
	{
		counter += ft_print_c(result[i]);
		i++;
	}
	return (counter);
}

int	ft_print_lower_x(unsigned int value)
{
	int				i;
	int				counter;
	char			result[9];

	counter = 0;
	i = 7;
	result[8] = '\0';
	if (value == 0)
	{
		result[i] = '0';
		counter += ft_print_c(result[i]);
	}
    get_hex(value, result, &i);
	i++;
	while (i < 8)
	{
		counter += ft_print_c(result[i]);
		i++;
	}
	return (counter);
}
*/