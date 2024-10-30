/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:02 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 20:43:28 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    char    *str;

    i = 0;
    str = (char *)s;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (str + i);
        i++;
    }
    if (s[i] != '\0' && (char)c == '\0')
        return (str + i);
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