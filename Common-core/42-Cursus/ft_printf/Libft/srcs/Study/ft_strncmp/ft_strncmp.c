/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:48:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main()
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, Earth!";
    const char *str3 = "Hello";

    printf("str1 e str2 (7 char): %d\n", ft_strncmp(str1, str2, 7));
    printf("str1 e str2 (12 char): %d\n", ft_strncmp(str1, str2, 12));
    printf("str1 e str3 (5 char): %d\n", ft_strncmp(str1, str3, 5));
    printf("str1 e str3 (10 char): %d\n", ft_strncmp(str1, str3, 10));

    return (0);
}
*/