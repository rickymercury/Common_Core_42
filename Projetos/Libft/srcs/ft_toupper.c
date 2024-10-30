/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:49:03 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 22:04:19 by rickymercur      ###   ########.fr       */
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
int main(void)
{
    char lowercase = 'a';
    char uppercase = 'B';
    char non_alpha = '1';

    printf("'%c' to upper: '%c'\n", lowercase, ft_toupper(lowercase));
    printf("'%c' to upper: '%c'\n", uppercase, ft_toupper(uppercase));
    printf("'%c' to upper: '%c'\n", non_alpha, ft_toupper(non_alpha));

    return 0;
}
*/