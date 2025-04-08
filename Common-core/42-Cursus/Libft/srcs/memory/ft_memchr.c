/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:41:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/08 23:54:49 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));  // return ((void *) &str[i]);
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