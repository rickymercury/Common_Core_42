/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:10 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:38:02 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int numlen(int nb)
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

char *ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nbr;

	nbr = n;
	size = numlen(n);
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

/*
void ft_print_result(char const *s)
{
    int len = 0;

    while (s[len])
        len++;
    write(1, s, len);
}

int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return 0;

    if ((arg = atoi(argv[1])) == 1)
    {
        char *res = ft_itoa(0);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 2)
    {
        char *res = ft_itoa(9);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 3)
    {
        char *res = ft_itoa(-9);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 4)
    {
        char *res = ft_itoa(10);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 5)
    {
        char *res = ft_itoa(-10);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 6)
    {
        char *res = ft_itoa(8124);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 7)
    {
        char *res = ft_itoa(-9874);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 8)
    {
        char *res = ft_itoa(543000);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 9)
    {
        char *res = ft_itoa(-2147483648LL);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }
    else if (arg == 10)
    {
        char *res = ft_itoa(2147483647);
        ft_print_result(res);
        free(res);
        write(1, "\n", 1);
    }

    return 0;
}
*/

/*
OUTPUT:

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_itoa.c -o ft_itoa && for i in {1..11}; do ./ft_itoa $i; done
0
9
-9
10
-10
8124
-9874
543000
-2147483648
2147483647
*/