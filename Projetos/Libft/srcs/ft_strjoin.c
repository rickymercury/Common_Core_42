/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:31 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 21:02:14 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	size_t			stotal;
	char		*ptr;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	stotal = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((stotal + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>

int main()
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *joined = ft_strjoin(s1, s2);

    if (joined)
    {
        printf("%s\n", joined);
        free(joined);
    }
    return 0;
}
*/