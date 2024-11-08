/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:44:32 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 22:12:31 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
    if (n == 0)
		return (0);
	while ((ptr1[i] == ptr2[i]) && (i < n - 1))
		i++;
	return (ptr1[i] - ptr2[i]);
}

/*
void ft_print_result(int n)
{
    if (n > 0)
        printf("1\n"); 
    else if (n < 0)
        printf("-1\n");
    else
        printf("0\n");  
}

int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return (0);
    
    arg = atoi(argv[1]);
    
    if (arg == 1)
    {
        printf("Comparação entre \"salut\" com \"salut\": ");
        ft_print_result(ft_memcmp("salut", "salut", 5));
    }
    else if (arg == 2)
    {
        printf("Comparação entre\"t\\200\" com \"t\\0\": ");
        ft_print_result(ft_memcmp("t\200", "t\0", 2));
    }
    else if (arg == 3)
    {
        printf("Comparação entre \"testss\" com \"test\": ");
        ft_print_result(ft_memcmp("testss", "test", 5));
    }
    else if (arg == 4)
    {
        printf("Comparação entre \"test\" com \"tEst\": ");
        ft_print_result(ft_memcmp("test", "tEst", 4));
    }
    else if (arg == 5)
    {
        printf("Comparação entre \"\" com \"test\": ");
        ft_print_result(ft_memcmp("", "test", 4));
    }
    else if (arg == 6)
    {
        printf("Comparação entre \"test\" com \"\": ");
        ft_print_result(ft_memcmp("test", "", 4));
    }
    else if (arg == 7)
    {
        printf("Comparação entre \"abcdefghij\" com \"abcdefgxyz\": ");
        ft_print_result(ft_memcmp("abcdefghij", "abcdefgxyz", 7));
    }
    else if (arg == 8)
    {
        printf("Comparação entre \"abcdefgh\" com \"abcdwxyz\": ");
        ft_print_result(ft_memcmp("abcdefgh", "abcdwxyz", 6));
    }
    else if (arg == 9)
    {
        printf("Comparação entre \"zyxbcdefgh\" com \"abcdefgxyz\": ");
        ft_print_result(ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
    }

    return (0);
}
*/

/*
OUTPUT:

sh-5.2$ cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_memcmp.c -o ft_memcmp && for i in {1..9}; do ./ft_memcmp $i; done
Comparação entre "salut" com "salut": 0
Comparação entre"t\200" com "t\0": 1
Comparação entre "testss" com "test": 1
Comparação entre "test" com "tEst": 1
Comparação entre "" com "test": -1
Comparação entre "test" com "": 1
Comparação entre "abcdefghij" com "abcdefgxyz": 0
Comparação entre "abcdefgh" com "abcdwxyz": -1
Comparação entre "zyxbcdefgh" com "abcdefgxyz": 0
*/


/* DESCRIPTION: memcmp compares two blocks of memory specified by ptr1 and ptr2.
The number of bytes to be compared is n . The null character is treated like any
other character and participates in the comparison, which is performed using the
standard EBCDIC collating sequence.

RETURN VALUE: memcmp returns 0 if the two blocks are equal, an integer less
than 0 if the first block is less than the second, or an integer greater than 0
if the first block is greater than the second.  */


/* SIMPLIER MAIN

int	main(void)
{
	char	s1[] = "Hello World";
	char	s2[] = "Hello Warld";
	int		n;

	n = 42;
	printf("%s vs %s = %d\n", s1, s2, ft_memcmp(s1, s2, n));
}
*/