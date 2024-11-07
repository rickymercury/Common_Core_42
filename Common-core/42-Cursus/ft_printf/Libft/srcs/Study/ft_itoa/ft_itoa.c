/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:10 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 13:22:40 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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