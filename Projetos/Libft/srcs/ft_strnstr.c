/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:22 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 21:34:16 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] != '\0' && (i + j) < len && str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}


/*
int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle = "world";

    char *result = ft_strnstr(haystack, needle, 15);

    if (result)
        printf("Found: %s\n", result);
    else
        printf("Not found\n");

    return 0;
}
*/