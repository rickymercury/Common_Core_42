/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:32 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 13:44:59 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int main() 
{
    char str1[] = "Hello";
    char str2[] = "Hella";
    char str3[] = "HeLLo";

    printf("str1 e str2: %d\n", ft_memcmp(str1, str2, 5));
    printf("str1 e str3: %d\n", ft_memcmp(str1, str3, 5));
    printf("str1 e str3 até 3 bytes: %d\n", ft_memcmp(str1, str3, 3));
    return 0;
}
*/