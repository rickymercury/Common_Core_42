/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:02 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:45:03 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}


/*
#include <stdio.h>

int main() {
    char str[50];

    ft_memset(str, 'A', 10);
    str[10] = '\0';

    printf("str após ft_memset: %s\n", str);

    return (0);
}
*/
