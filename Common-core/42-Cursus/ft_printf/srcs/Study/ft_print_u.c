/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:07:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/13 01:55:35 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_digits(long nbr)
{
    int count;

    count = 0;
    if (nbr == 0)
        return (1);
    while (nbr > 0)
    {
        nbr /= 10;
		count++;
    }
    return (count);
}

int ft_print_u(unsigned int n)
{
    unsigned long nbr;
    int digit_count;

    nbr = n;
    if (nbr == 0)
    {
        ft_print_c('0');
        return (1);
    }
    digit_count = count_digits(nbr);
    if (nbr >= 10)
        ft_print_u(nbr / 10);
    ft_print_c(nbr % 10 + '0');
    return (digit_count);
}






/* NON-RECURSIVE

static size_t u_digits(unsigned int n)
{
    size_t digits;

	digits = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 10;
        digits++;
    }
    return (digits);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		size;

	size = u_digits(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (size > 0)
	{
		str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}

int ft_print_u(unsigned int n)
{
    int   len;
    char *str;

    if (n == 0)
        return (write(1, "0", 1));
    str = ft_utoa(n);
    if (!str)
        return (-1);
    len = 0;
    while (str[len] != '\0')
        len++;
    write(1, str, len);
    free(str);
    return (len);
}
*/