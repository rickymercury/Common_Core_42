/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:47 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 23:11:57 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char *s;
    unsigned char *d;
	size_t i;

    if (!src || !dest)
        return (NULL);
    
    s = (unsigned char *)src;
    d = (unsigned char *)dest;

    if (d > s)
    {
        while (len-- > 0)
            d[len] = s[len];
    }
    else
    {
        i = 0;
        while (i < len)
        {
            d[i] = s[i];
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
