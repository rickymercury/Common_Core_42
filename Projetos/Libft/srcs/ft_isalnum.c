/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:18 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:43:19 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
	printf("ft_isalnum('5'): %d\n",ft_isalnum('5'));
    printf("ft_isalnum('H'): %d\n",ft_isalnum('H'));
    printf("ft_isalnum('&'): %d\n",ft_isalnum('&'));
    printf("ft_isalnum('200'): %d\n",ft_isalnum(200));
    printf("ft_isalnum('0'): %d\n",ft_isalnum(0));
}
*/
