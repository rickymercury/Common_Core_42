/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:53:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 19:11:40 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int ft_num_len(long nb)
{
	int len;

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

int ft_print_num(int n)
{
    long nb;
    int len;
    int i;
    char *str;
    
	nb = n;
    if (nb == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    len = ft_numlen(nb);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return (-1);
    str[len] = '\0';
    if (nb < 0)
    {
        str[0] = '-';
        nb *= -1;
    }
    i = len - 1;
    while (nb > 0 && i >= 0)
    {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        i--;
    }
    write(1, str, len);
    free(str);
    return len;
}
*/


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int		len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

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
	size --;
	while (nbr > 0 && size >= 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (str);
}

int	ft_print_num(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}


/*
#include "ft_printf.h"

int	ft_printf_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
		len += ft_printf_nbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_printf_nbr(nb / 10);
		len += ft_printf_nbr(nb % 10);
	}
	else
	{
		nb += 48;
		len += write(1, &nb, 1);
	}
	return (len);
}
*/