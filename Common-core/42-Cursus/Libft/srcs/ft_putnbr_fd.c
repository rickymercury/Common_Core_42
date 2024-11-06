/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:27 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 18:39:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
    write(fd, &c, 1);
}

/*
int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return (0);
    else if ((arg = atoi(argv[1])) == 1)
    {
        ft_putnbr_fd(0, 2);
        ft_putchar_fd('\n', 2);
    }
    else if (arg == 2)
    {
        ft_putnbr_fd(5, 1);
        ft_putchar_fd('\n', 1);
    }
    else if (arg == 3)
    {
        ft_putnbr_fd(-5, 2);
        ft_putchar_fd('\n', 2);
    }
    else if (arg == 4)
    {
        ft_putnbr_fd(42, 1);
        ft_putchar_fd('\n', 1);
    }
    else if (arg == 5)
    {
        ft_putnbr_fd(-57, 2);
        ft_putchar_fd('\n', 2);
    }
    else if (arg == 6)
    {
        ft_putnbr_fd(164189, 1);
        ft_putchar_fd('\n', 1);
    }
    else if (arg == 7)
    {
        ft_putnbr_fd(-987441, 2);
        ft_putchar_fd('\n', 2);
    }
    else if (arg == 8)
    {
        ft_putnbr_fd(2147483647, 1);
        ft_putchar_fd('\n', 1);
    }
    else if (arg == 9)
    {
        ft_putnbr_fd(-2147483648LL, 2);
        ft_putchar_fd('\n', 2);
    }

    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_putnbr_fd.c ft_putchar_fd.c -o ft_putnbr_fd && for i in {1..11}; do ./ft_putnbr_fd $i; done
0
5
-5
42
-57
164189
-987441
2147483647
-2147483648
*/