/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:17 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 18:23:49 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int i;

    i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*
int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return (0);
    else if ((arg = atoi(argv[1])) == 1)
    {
        ft_putendl_fd("lorem ipsum dolor sit amet", 2);
    }
    else if (arg == 2)
    {
        ft_putendl_fd("  loremipsumdolorsit amet  ", 1);
    }
    else if (arg == 3)
    {
        ft_putendl_fd("", 2);
    }
    else if (arg == 4)
    {
        ft_putendl_fd("lorem ipsum do\0lor sit amet", 1);
    }

    return (0);
}
*/

/*
OUTPUT: 

lorem ipsum dolor sit amet
  loremipsumdolorsit amet  

lorem ipsum do
*/