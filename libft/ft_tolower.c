/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:49:06 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:49:07 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
int main(void)
{
    char uppercase = 'A';
    char lowercase = 'b';
    char non_alpha = '1';

    printf("'%c' to lower: '%c'\n", uppercase, ft_tolower(uppercase));
    printf("'%c' to lower: '%c'\n", lowercase, ft_tolower(lowercase));
    printf("'%c' to lower: '%c'\n", non_alpha, ft_tolower(non_alpha));

    return 0;
}
*/