/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:42:51 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:20:21 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
int main(int argc, const char *argv[])
{
    void    *mem;

    if (argc == 1 || !(mem = malloc(sizeof(*mem) * 5)))
        return (0);
    
    if (atoi(argv[1]) == 1)
    {
        memset(mem, 'e', 5);
        ft_bzero(mem, 4);
        write(1, mem, 5);
        write(1, "\n", 1);
    }
    else if (atoi(argv[1]) == 2)
    {
        memset(mem, 'e', 5);
        ft_bzero(mem, 0);
        write(1, mem, 5);
        write(1, "\n", 1);
    }

    free(mem);
    return (0);
}
*/

/*
OUTPUT:

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_bzero.c -o ft_bzero && for i in {1..2}; do ./ft_bzero $i; done
e
eeeee
*/

// Sets the first n bytes of the byte area starting at s to zero.


/* SIMPLIER MAIN

int	main(void)
{
	char s[] = "42 Porto";
	int n = 3;
	int size = 0;
	int i = 0;
	while (s[size] != '\0')
		size++;
	printf("%s -> ", s);
	ft_bzero(s, n);
	while (size > 0)
	{
		printf("%c", s[i]);
		i++;
		size--;
	}
	printf("\n");
}*/