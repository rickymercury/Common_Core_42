/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:34 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 18:49:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return (0);
    else if ((arg = atoi(argv[1])) == 1)
    {
        ft_putstr_fd("lorem ipsum dolor sit amet", 2);
        ft_putstr_fd("\n", 2);
    }
    else if (arg == 2)
    {
        ft_putstr_fd("  loremipsumdolor\tsit amet  ", 1);
        ft_putstr_fd("\n", 1);
    }
    else if (arg == 4)
    {
        ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
        ft_putstr_fd("\n", 1);
    }
    return (0);
}
*/