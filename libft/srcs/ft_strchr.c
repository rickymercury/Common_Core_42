/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:02 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 22:32:38 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    if (s[i] != '\0' && (char)c == '\0')
        return ((char *)&s[i]);
    return (NULL);
}

/*
int main() 
{
    const char *str = "Hello, World!";
    char *result;

    result = ft_strchr(str, 'W');
    if (result) 
        printf("Found: %s\n", result);
    else 
        printf("Character not found.\n");
    result = ft_strchr(str, 'z');
    if (result)
        printf("Found: %s\n", result);
    else
        printf("Character not found.\n");

    return (0);
}
*/