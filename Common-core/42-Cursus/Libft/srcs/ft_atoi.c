/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:18:38 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:44:24 by rmedeiro         ###   ########.fr       */
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

/* int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("ft_atoi: %d\n", ft_atoi(argv[1]));
		printf("atoi: %d\n", atoi(argv[1]));
	}
	return (0);
} */

/* int main()
{
	char atoi_number1[] = "	-4839281 wds";
	char atoi_number2[] = " +4839wds281";

	printf("ft_atoi: %d\n", ft_atoi(atoi_number1));
	printf("original: %d\n\n", atoi(atoi_number1));

	printf("ft_atoi: %d\n", ft_atoi(atoi_number2));
	printf("original: %d\n\n", atoi(atoi_number2));

	return (0);
} */