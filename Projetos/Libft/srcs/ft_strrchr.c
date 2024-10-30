/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:30 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 21:41:04 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
    char    *str;

	i = 0;
    str = (char *)s;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	return (NULL);
}

/*
int main(void)
{
    const char *str = "Hello, world!";
    char *result;

    result = ft_strrchr(str, 'o');
    if (result)
        printf("Last occurrence of 'o': %s\n", result);
    else
        printf("'o' not found\n");

    result = ft_strrchr(str, 'x');
    if (result)
        printf("Last occurrence of 'x': %s\n", result);
    else
        printf("'x' not found\n");

    return 0;
}
*/