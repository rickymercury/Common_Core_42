/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:10 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 23:26:16 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nbr;

	nbr = (long int) n;
	size = ft_numlen(n);
	str = malloc((1 + size) * sizeof(char));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
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


/*
int main() 
{
    char *result;

    result = ft_itoa(0);
    printf("Número: 0 -> String: %s\n", result);
    free(result);

    result = ft_itoa(42);
    printf("Número: 42 -> String: %s\n", result);
    free(result);

    result = ft_itoa(-42);
    printf("Número: -42 -> String: %s\n", result);
    free(result);

    result = ft_itoa(123);
    printf("Número: 123 -> String: %s\n", result);
    free(result); 

    result = ft_itoa(-123);
    printf("Número: -123 -> String: %s\n", result);
    free(result);

    return (0);
}
*/