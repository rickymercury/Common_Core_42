/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 20:46:49 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t  len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = ((char *)malloc(sizeof(char) * (len +1)));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
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