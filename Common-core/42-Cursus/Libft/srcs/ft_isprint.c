/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:56 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:43:57 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
int main() 
{
    printf("ft_isprint(' '): %d\n", ft_isprint(' '));
    printf("ft_isprint('A'): %d\n", ft_isprint('A'));
    printf("ft_isprint('z'): %d\n", ft_isprint('z'));
    printf("ft_isprint('~'): %d\n", ft_isprint('~'));
    printf("ft_isprint(31): %d\n", ft_isprint(31));
    printf("ft_isprint(127): %d\n", ft_isprint(127));
    printf("ft_isprint(128): %d\n", ft_isprint(128));
    
    return (0);
}
*/