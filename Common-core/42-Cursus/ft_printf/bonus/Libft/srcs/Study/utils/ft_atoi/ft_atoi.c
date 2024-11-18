/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:42:47 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:03:37 by rickymercur      ###   ########.fr       */
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
======= Exemple for the number 421337 =======

digit = 0 * 10 + 52 - 48 = 4
digit = 4 * 10 + 50 - 48 = 42
digit = 42 * 10 + 49 - 48 = 421
digit = 421 * 10 + 51 - 48 = 4213
digit = 4213 * 10 + 51 - 48 = 42133
digit = 42133 * 10 + 55 - 48 = 421337
*/

/*
void	ft_print_result2(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
	else
	{
		ft_print_result2('-');
		if (n <= -10)
			ft_print_result(n / -10);
		ft_print_result2(n % -10 * -1 + '0');
	}
}

int main(int argc, const char *argv[])
{
	int	arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		ft_print_result(ft_atoi("0"));
		write(1, "\n", 1);
	}
	else if (arg == 2)
	{
		ft_print_result(ft_atoi("546:5"));
		write(1, "\n", 1);
	}
	else if (arg == 3)
	{
		ft_print_result(ft_atoi("-4886"));
		write(1, "\n", 1);
	}
	else if (arg == 4)
	{
		ft_print_result(ft_atoi("+548"));
		write(1, "\n", 1);
	}
	else if (arg == 5)
	{
		ft_print_result(ft_atoi("054854"));
		write(1, "\n", 1);
	}
	else if (arg == 6)
	{
		ft_print_result(ft_atoi("000074"));
		write(1, "\n", 1);
	}
	else if (arg == 7)
	{
		ft_print_result(ft_atoi("+-54"));
		write(1, "\n", 1);
	}
	else if (arg == 8)
	{
		ft_print_result(ft_atoi("-+48"));
		write(1, "\n", 1);
	}
	else if (arg == 9)
	{
		ft_print_result(ft_atoi("--47"));
		write(1, "\n", 1);
	}
	else if (arg == 10)
	{
		ft_print_result(ft_atoi("++47"));
		write(1, "\n", 1);
	}
	else if (arg == 11)
	{
		ft_print_result(ft_atoi("+47+5"));
		write(1, "\n", 1);
	}
	else if (arg == 12)
	{
		ft_print_result(ft_atoi("-47-5"));
		write(1, "\n", 1);
	}
	else if (arg == 13)
	{
		ft_print_result(ft_atoi("\e475"));
		write(1, "\n", 1);
	}
	else if (arg == 14)
	{
		ft_print_result(ft_atoi("\t\n\r\v\f  469 \n"));
		write(1, "\n", 1);
	}
	else if (arg == 15)
	{
		ft_print_result(ft_atoi("-2147483648"));
		write(1, "\n", 1);
	}
	else if (arg == 16)
	{
		ft_print_result(ft_atoi("2147483647"));
		write(1, "\n", 1);
	}
	else if (arg == 17)
	{
		ft_print_result(ft_atoi("\t\n\r\v\fd469 \n"));
		write(1, "\n", 1);
	}
	else if (arg == 18)
	{
		ft_print_result(ft_atoi("\n\n\n  -46\b9 \n5d6"));
		write(1, "\n", 1);
	}
	else if (arg == 19)
	{
		ft_print_result(ft_atoi(""));
		write(1, "\n", 1);
	}
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra ft_atoi.c -o ft_atoi && for i in {1..19}; do ./ft_atoi $i; done
0
546
-4886
548
54854
74
0
0
0
0
47
-47
0
469
-2147483648
2147483647
0
-46
0

*/