/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:34 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 17:24:40 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

/*
int	main(void)
{
	ft_putstr_fd("Hello, world!", 1);
	write(1, "\n", 1);
	ft_putstr_fd(NULL, 1);
	write(1, "\n", 1);
	return (0);
}
*/