/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:49:03 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 18:08:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
int main(int argc, const char *argv[])
{
    int i;
    int c;
    int arg;

    if (argc < 2)
        return 0;

    if ((arg = atoi(argv[1])) == 1)
    {
        write(1, "Testing ft_toupper from 'A' to 'Z':\n", 37);
        i = 'A';
        while (i <= 'Z')
        {
            c = ft_toupper(i);
            write(1, &i, 1);
            write(1, " -> ", 4);
            write(1, &c, 1);
            write(1, "\n", 1);
            i++;
        }
    }
    else if ((arg = atoi(argv[1])) == 2)
    {
        write(1, "Testing ft_toupper from 'a' to 'z':\n", 37);
        i = 'a';
        while (i <= 'z')
        {
            c = ft_toupper(i);
            write(1, &i, 1);
            write(1, " -> ", 4);
            write(1, &c, 1);
            write(1, "\n", 1);
            i++;
        }
    }
  
    return 0;
}
*/