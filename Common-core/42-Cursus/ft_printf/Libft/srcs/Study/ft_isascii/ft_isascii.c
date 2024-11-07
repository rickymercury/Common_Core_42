/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:35 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:43:35 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int main() 
{
    printf("ft_isascii(65): %d\n", ft_isascii(65)); 
    printf("ft_isascii(97): %d\n", ft_isascii(97));  
    printf("ft_isascii(128): %d\n", ft_isascii(128)); 
    printf("ft_isascii(-1): %d\n", ft_isascii(-1));  
    printf("ft_isascii(0): %d\n", ft_isascii(0));    
    printf("ft_isascii(127): %d\n", ft_isascii(127)); 
    
    return (0);
}
*/
