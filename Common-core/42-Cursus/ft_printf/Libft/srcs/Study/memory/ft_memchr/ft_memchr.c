/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:23 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/04 23:51:40 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}


/*
int main(int argc, const char *argv[])
{
    const char *str;

    if (argc < 2)
        return 0;

    int arg = atoi(argv[1]);

    if (arg == 1)
    {
        str = ft_memchr("bonjour", 'b', 4);
        if (!str)
            printf("Não encontrou: NULL\n");
        else
            printf("Procurar 'b' em 'bonjour' nos primeiros 4 caracteres | Resultado: %s\n", str);
        printf("\n");
    }

    if (arg == 2)
    {
        str = ft_memchr("bonjour", 'o', 7);
        if (!str)
            printf("Não encontrou: NULL\n");
        else
            printf("Procurar 'o' em 'bonjour' nos primeiros 7 caracteres | Resultado: %s\n", str);
        printf("\n");
    }

    if (arg == 3)
    {
        str = ft_memchr("bonjourno", 'n', 2);
        if (!str)
            printf("Não encontrou: NULL\n");
        else
            printf("Procurar 'n' em 'bonjourno' nos primeiros 2 caracteres | Resultado: %s\n", str);
        printf("\n");
    }

    if (arg == 4)
    {
        str = ft_memchr("bonjour", 'j', 6);
        if (!str)
            printf("Não encontrou: NULL\n");
        else
            printf("Procurar 'j' em 'bonjour' nos primeiros 6 caracteres | Resultado: %s\n", str);
        printf("\n");
    }

    if (arg == 5)
    {
        str = ft_memchr("bonjour", 's', 7);
        if (!str)
            printf("Não encontrou: NULL\n");
        else
            printf("Procurar 's' em 'bonjour' nos primeiros 7 caracteres: %s\n", str);
        printf("\n");
    }

    return (0);
}
*/

/*
OUTPUT:

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_memchr.c -o ft_memchr && for i in {1..5}; do ./ft_memchr $i; done

Procurar 'b' em 'bonjour' nos primeiros 4 caracteres | Resultado: bonjour

Procurar 'o' em 'bonjour' nos primeiros 7 caracteres | Resultado: onjour

Não encontrou: NULL

Procurar 'j' em 'bonjour' nos primeiros 6 caracteres | Resultado: jour

Não encontrou: NULL

*/