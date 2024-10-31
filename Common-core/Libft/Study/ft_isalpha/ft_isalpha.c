/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:27 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:43:28 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main() 
{
    printf("ft_isalpha('a'): %d\n", ft_isalpha('a'));
    printf("ft_isalpha('Z'): %d\n", ft_isalpha('Z'));
    printf("ft_isalpha('5'): %d\n", ft_isalpha('5'));
    printf("ft_isalpha('&'): %d\n", ft_isalpha('&'));
    printf("ft_isalpha(' '): %d\n", ft_isalpha(' '));
    
    return (0);
}
*/