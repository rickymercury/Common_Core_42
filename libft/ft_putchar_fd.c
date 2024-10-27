/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:08 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:45:08 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main() 
{
    ft_putchar_fd('H', 1);
    ft_putchar_fd('e', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('o', 1);
    ft_putchar_fd(',', 1);
    ft_putchar_fd(' ', 1);
    ft_putchar_fd('W', 1);
    ft_putchar_fd('o', 1);
    ft_putchar_fd('r', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('d', 1);
    ft_putchar_fd('!', 1);
    ft_putchar_fd('\n', 1);

    return 0;
}
*/