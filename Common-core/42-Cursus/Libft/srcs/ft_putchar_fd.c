/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:08 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 18:18:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write (fd, &c, 1);
}

/*
int main(int argc, const char *argv[])
{
    int i;
    int arg;

    if (argc == 1)
        return (0);
  
    if ((arg = atoi(argv[1])) == 1)
    {
        i = '0';
        while (i <= '9')
        {
            ft_putchar_fd(i, 1);
            i++;
        }
        ft_putchar_fd('\n', 1);
    }
    else if ((arg = atoi(argv[1])) == 2)
    {
        i = 58;
        while (i <= 64)
        {
            ft_putchar_fd(i, 2);
            i++;
        }
        ft_putchar_fd('\n', 2);
    }
    else if ((arg = atoi(argv[1])) == 3)
    {
        i = 'A';
        while (i <= 'Z')
        {
            ft_putchar_fd(i, 1);
            i++;
        }
        ft_putchar_fd('\n', 1);
    }
    else if ((arg = atoi(argv[1])) == 4)
    {
        i = 91;
        while (i <= 96)
        {
            ft_putchar_fd(i, 2);
            i++;
        }
        ft_putchar_fd('\n', 2);
    }
    else if ((arg = atoi(argv[1])) == 5)
    {
        i = 'a';
        while (i <= 'z')
        {
            ft_putchar_fd(i, 1);
            i++;
        }
        ft_putchar_fd('\n', 1);
    }
    else if ((arg = atoi(argv[1])) == 6)
    {
        i = 123;
        while (i <= 127)
        {
            ft_putchar_fd(i, 2);
            i++;
        }
        ft_putchar_fd('\n', 2);
    }

    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_putchar_fd.c -o ft_putchar_fd && for i in {1..11}; do ./ft_putchar_fd $i; done
0123456789
:;<=>?@
ABCDEFGHIJKLMNOPQRSTUVWXYZ
[\]^_`
abcdefghijklmnopqrstuvwxyz
{|}~
*/