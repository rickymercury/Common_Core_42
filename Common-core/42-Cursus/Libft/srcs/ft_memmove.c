/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:47 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 22:21:28 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}

/*
int		main(int argc, const char *argv[])
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	int		arg;

	dest = src + 1;
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (dest != ft_memmove(dest, "consectetur", 5))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
        write(1,"\n", 1);
	}
	else if (arg == 2)
	{
		if (dest != ft_memmove(dest, "con\0sec\0\0te\0tur", 10))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
        write(1,"\n", 1);
	}
	else if (arg == 3)
	{
		if (dest != ft_memmove(dest, src, 8))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
        write(1,"\n", 1);
	}
	else if (arg == 4)
	{
		if (src != ft_memmove(src, dest, 8))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
        write(1,"\n", 1);
	}
	else if (arg == 5)
	{
		if (src != ft_memmove(src, dest, 0))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
        write(1,"\n", 1);
	}
	return (0);
}
*/


/*
OUTPUT:

sh-5.2$ cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_memmove.c -o ft_memmove && for i in {1..5}; do ./ft_memmove $i; done
conseipsum dolor sit a
consect dolor sit a
lorem ipum dolor sit a
rem ipssum dolor sit a
orem ipsum dolor sit a
*/


/* DESCRIPTION: memmove is identical to memcpy except that the copy is
guaranteed to work correctly even if the to and from objects overlap. On
completion of the call, the n bytes addressed by to are identical to the n bytes
addressed by from before the call.

RETURN VALUE: memmove returns a pointer to the to area. */

/* SIMPLIER MAIN

int	main(void)
{
	char dest[20] = "  42  Porto";
	ft_memmove(dest, "Hello world!", 5);
	printf("%s\n", dest);
}*/

/* The loop determines how the memory is copied: backwards of forwards,
depending on the size of dest and src*/