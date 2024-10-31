/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:47 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 13:59:16 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char *ptr2;
    unsigned char *ptr1;
	size_t            i;
    
    if (src == NULL || dest == NULL)
        return (NULL);
    ptr1 = (unsigned char *)src;
    ptr2 = (unsigned char *)dest;
    if (ptr2 > ptr1)
    {
        while (len-- > 0)
            ptr2[len] = ptr1[len];
    }
    else
    {
        i = 0;
        while (i < len)
        {
            ptr2[i] = ptr1[i];
            i++;
        }
    }
    return (dest);
}


/*
int main() 
{
    char src[] = "Hello, world!";
    char dest[20];

    ft_memmove(dest, src, 13);
    dest[13] = '\0';

    printf("Source: %s\n", src);
    printf("Destination after memmove: %s\n", dest);

    ft_memmove(src + 7, src, 6);
    printf("Overlapping source after memmove: %s\n", src);

    return (0);
}
*/