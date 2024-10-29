/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:42:47 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 22:51:48 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*str1 = "-42";
	const char	*str2 = "   -123";
	const char	*str3 = "   +567";
	const char	*str4 = "   987abc";
	const char	*str5 = "-2147483648";

	printf("String: '%s' -> Integer:%d\n", str1, ft_atoi(str1));
	printf("String: '%s' -> Integer:%d\n", str2, ft_atoi(str2));
	printf("String: '%s' -> Integer:%d\n", str3, ft_atoi(str3));
	printf("String: '%s' -> Integer:%d\n", str4, ft_atoi(str4));
	printf("String: '%s' -> Integer:%d\n", str5, ft_atoi(str5));

	return (0);
}
*/