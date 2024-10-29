/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:42 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:43:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int main() 
{
    printf("ft_isdigit('0'): %d\n", ft_isdigit('0'));
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
    printf("ft_isdigit('9'): %d\n", ft_isdigit('9'));
    printf("ft_isdigit('a'): %d\n", ft_isdigit('a'));
    printf("ft_isdigit('@'): %d\n", ft_isdigit('@'));
    printf("ft_isdigit(10): %d\n", ft_isdigit(10));
    printf("ft_isdigit(48): %d\n", ft_isdigit(48));

    return (0);
}
*/
