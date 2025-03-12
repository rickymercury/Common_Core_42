/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:08:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:52:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

/* int main()
{
    ft_putchar_fd('H', 1);
    ft_putchar_fd('e',1);
    ft_putchar_fd('l',1);
    ft_putchar_fd('l',1);
    ft_putchar_fd('o',1);
    ft_putchar_fd('!',1);
    ft_putchar_fd('\n',1);
} */