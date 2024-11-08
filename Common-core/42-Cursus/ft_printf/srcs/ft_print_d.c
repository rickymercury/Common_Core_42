/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:53:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:34:37 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	int	count;

    count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char *ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nbr;

	nbr = n;
	size = count_digits(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[size--] = '\0';
	while (nbr > 0 && size >= 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

int	ft_print_d(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_print_s("-2147483648\n"));
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_s(str);
	len += ft_print_s("\n");
	free(str);
	return (len);
}