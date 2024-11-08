/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:08 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:19:44 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			total_bytes;
	unsigned char	*ptr;

	i = 0;
	total_bytes = count * size;
	ptr = (unsigned char *) malloc(total_bytes);
	if (ptr == NULL)
		return (NULL);
	while (i < total_bytes)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
*/

/* Reserves storage space for an array of num elements, each of length size
bytes. The calloc() function then gives all the bits of each element an initial
value of 0.
The calloc() function returns a pointer to the reserved space. The storage space
to which the returned value points is aligned for storage of any type of
object.*/

/*
int main(int argc, const char *argv[])
{
    char *str;

    if (argc == 1)
        return (0);
    if (atoi(argv[1]) == 1) 
    {
        str = (char *)ft_calloc(30, 1);
        if (!str)
            write(1, "NULL\n", 6);
        else 
        {
            write(1, str, 30);
            write(1, "\n", 1);
            free(str);
        }
    }
    else if (atoi(argv[1]) == 2) 
    {
        str = (char *)ft_calloc(10, sizeof(char));
        if (!str)
            write(1, "NULL\n", 6);
        else 
        {
            write(1, str, 10);
            write(1, "\n", 1);
            free(str);
        }
    }
    else if (atoi(argv[1]) == 3) 
    {
        str = (char *)ft_calloc(0, 10);
        if (!str)
            write(1, "NULL\n", 6);
        else 
        {
            write(1, str, 0);
            write(1, "\n", 1);
            free(str);
        }
    }
    else if (atoi(argv[1]) == 4) 
    {
        str = (char *)ft_calloc(1000000, sizeof(char));
        if (!str)
            write(1, "NULL\n", 6);
        else 
        {
            write(1, str, 1000000);
            write(1, "\n", 1);
            free(str);
        }
    }
   
    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_calloc.c -o ft_calloc
sh-5.2$ ./ft_calloc 1

sh-5.2$ ./ft_calloc 2

sh-5.2$ ./ft_calloc 3

sh-5.2$ ./ft_calloc 4

*/


/*
OUTPUT:

cc -Wall -Werror -Wextra -g ft_calloc.c -o ft_calloc
sh-5.2$ valgrind ./ft_calloc 4
==35338== Memcheck, a memory error detector
==35338== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==35338== Using Valgrind-3.23.0 and LibVEX; rerun with -h for copyright info
==35338== Command: ./ft_calloc 4
==35338== 

==35338== 
==35338== HEAP SUMMARY:
==35338==     in use at exit: 0 bytes in 0 blocks
==35338==   total heap usage: 1 allocs, 1 frees, 1,000,000 bytes allocated
==35338== 
==35338== All heap blocks were freed -- no leaks are possible
==35338== 
==35338== For lists of detected and suppressed errors, rerun with: -s
==35338== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/