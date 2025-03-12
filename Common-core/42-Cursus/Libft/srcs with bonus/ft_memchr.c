/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:53:28 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:50:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/* 
int main()
{
	size_t n = 2;
	int c = 'e';
	const char str_memchr[10]= "Hello";
	
	printf("ft_memchr: %p\n", ft_memchr(str_memchr, c, n));
	printf("memchr: %p\n", memchr(str_memchr, c, n));
}
*/