/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:46:12 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = ((char *)malloc(sizeof(char) * (len +1)));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main() 
{
    const char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);

    if (duplicate) 
    {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    } 
    else
        printf("Memory allocation failed.\n");

    return (0);
}
*/