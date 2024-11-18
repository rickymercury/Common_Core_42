/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:39 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 22:15:27 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int main(int argc, const char *argv[])
{
    void *mem;
    int arg;

    if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
        return (0);

    memset(mem, 'j', 30);

    if ((arg = atoi(argv[1])) == 1)
    {
        if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
            write(1, "dest's address was not returned\n", 31);
        write(1, mem, 30);
        write(1, "\n", 1);
    }
    else if (arg == 2)
    {
        if (mem != ft_memcpy(mem, "zyxwvutst", 0))
            write(1, "dest's address was not returned\n", 31);
        write(1, mem, 30);
        write(1, "\n", 1);
    }
    else if (arg == 3)
    {
        if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
            write(1, "dest's address was not returned\n", 31);
        write(1, mem, 30);
        write(1, "\n", 1);
    }

    free(mem);
    
    return (0);
}
*/

/*
OUTPUT:

sh-5.2$ cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_memcpy.c -o ft_memcpy && for i in {1..3}; do ./ft_memcpy $i; done

zyxwvutsrqponmjjjjjjjjjjjjjjjj
jjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
zyxwvutjjjjjjjjjjjjjjjjjjj
*/

/* DESCRIPTION: memcpy copies the number of bytes specified by n from one area
of memory ( from ) to another ( to ). All bytes, including any null characters,
are copied.

RETURN VALUE: memcpy returns a pointer to the to area. */

/* SIMPLIER MAIN

int	main(void)
{
	char dest[20];
	ft_memcpy(dest, "Hello world!", 12);
	dest[12] = '\0';
	printf("%s\n", dest);
}*/