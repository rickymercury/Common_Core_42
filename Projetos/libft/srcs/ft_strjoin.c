/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:31 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 23:37:59 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while ((i - s1_len) < s2_len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
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