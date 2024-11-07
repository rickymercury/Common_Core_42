/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:53:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 20:25:24 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nbr;

	nbr = n;
	size = ft_numlen(n);
	str = (char *) malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	size--;
	while (nbr > 0 && size >= 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (str);
}

int	ft_print_d(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_print_s(str);
	free(str);
	return (len);
}