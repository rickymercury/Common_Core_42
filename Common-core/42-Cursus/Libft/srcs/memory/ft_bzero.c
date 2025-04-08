/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:24:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/08 23:54:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
} */

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