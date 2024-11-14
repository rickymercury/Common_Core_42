/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:08 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/14 00:07:35 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t element_size)
{
	void	*cal;

	if (nmemb != 0 && ((nmemb * element_size) / nmemb != element_size))
		return (NULL);
	cal = malloc(nmemb * element_size);
	if (!cal)
		return (NULL);
	ft_memset(cal, 0, nmemb * element_size);
	return (cal);
}

/* 
Reserves storage space for an array of num elements, each of length size
bytes. The calloc() function then gives all the bits of each element an initial
value of 0.
The calloc() function returns a pointer to the reserved space. The storage space
to which the returned value points is aligned for storage of any type of
object.
*/

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

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_calloc.c ft_memset.c -o ft_calloc && for i in {1..4}; do ./ft_calloc $i
; done




*/
