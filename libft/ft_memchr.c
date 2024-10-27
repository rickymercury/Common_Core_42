/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:23 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:44:24 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int main()
{
    char *str = "Hello, World!";
    char ch = 'o';
    char *result;

    result = ft_memchr(str, ch, 13);

    if (result != NULL)
        printf("Caractere '%c' encontrado na posição: %ld\n", ch, result - str);
    else
        printf("Caractere '%c' não encontrado.\n", ch);

    return (0);
}
*/