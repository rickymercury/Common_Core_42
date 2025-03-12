/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:23:04 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:52:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* 
int main()
{
	char str[10];

	size_t len = 13;
	ft_memset(str, 'A', len);
	printf("ft_memset: %s\n", str);
}
*/