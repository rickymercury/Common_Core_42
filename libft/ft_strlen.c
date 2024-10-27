/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:57 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:46:57 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
int main() 
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Benfica Campeão";
    const char *str3 = "Mother Mercury";

    printf("Length of string 1: %zu\n", ft_strlen(str1));
    printf("Length of string 2: %zu\n", ft_strlen(str2));
    printf("Length of string 3: %zu\n", ft_strlen(str3));

    return (0);
}
*/