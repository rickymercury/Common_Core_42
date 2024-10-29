/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:42:51 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 23:01:48 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, world!";

	printf("Before ft_bzero: %s\n", str);
	ft_bzero(str + 5, 5);
	printf("After ft_bzero: %s\\0\\0\\0\\0\\0world!\n", "Hello");

	return (0);
}
*/
