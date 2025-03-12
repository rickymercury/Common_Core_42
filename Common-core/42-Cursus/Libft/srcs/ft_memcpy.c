/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:59:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:51:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
    
	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

/* int main()
{
    char str1[] = "Hello";         
    char str2[] = "World";         
    char str3[] = "Hello";         
    char str4[] = "World";         

    size_t len = 5;

    printf("Antes da cópia:\n");
    printf("str1 (original): %s\n", str1);
    printf("str3 (original): %s\n", str3);

    ft_memcpy(str1, str2, len);
    printf("\nApós ft_memcpy:\n");
    printf("str1 (modificada): %s\n", str1);

    memcpy(str3, str4, len);
    printf("\nApós memcpy:\n");
    printf("str3 (modificada): %s\n", str3);

    return (0);
} */