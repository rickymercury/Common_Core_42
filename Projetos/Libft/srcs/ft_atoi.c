/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:42:47 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 12:35:46 by rickymercur      ###   ########.fr       */
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
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
int	main(void)
{
	const char	str[] = " -23-2k1020";
	const char	str1[] = " 23 45";
	const char	str2[] = " -+23";
	const char	str3[] = "+23";
	const char	str4[] = "++23";
	const char	str5[] = "+ 23";

	printf("FT_ATOI; %i\n", ft_atoi(str));
	printf("FT_ATOI; %i\n", ft_atoi(str1));
	printf("FT_ATOI; %i\n", ft_atoi(str2));
	printf("FT_ATOI; %i\n", ft_atoi(str3));
	printf("FT_ATOI; %i\n", ft_atoi(str4));
	printf("FT_ATOI; %i\n", ft_atoi(str5));
}
*/