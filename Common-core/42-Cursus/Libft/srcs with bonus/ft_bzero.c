/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:37:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:45:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
}

/* 
int main()
{
	char str1[5] = "Hello";
	char str2[5] = "Hello";
	size_t len = 5;
    
	printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
	ft_bzero(str1, len);
	printf("str1: %s\n", str1);
    
	memset(str2, 0, len);
	printf("str2: %s\n", str2);

    return (0);
} 
*/