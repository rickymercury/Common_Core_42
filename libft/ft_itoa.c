/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:10 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:44:13 by rickymercur      ###   ########.fr       */
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
	int		len;
	char	*str;
	long	nb;
    
    nb = n;
	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
    {
		str[0] = '0';
        str[1] = '\0';
        return (str);
    }
	str[len--] = '\0';
	while (nb)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
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