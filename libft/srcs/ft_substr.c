/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:50 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:48:51 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_size;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	if (start >= s_size)
		len = 0;
	else if (len > s_size - start)
		len = s_size - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main(void)
{
    const char *str = "Hello, World!";
    char *substr;

    substr = ft_substr(str, 7, 5);
    if (substr)
    {
        printf("Substring: '%s'\n", substr);
        free(substr);
    }
    else
        printf("Memory allocation failed.\n");

    substr = ft_substr(str, 15, 5);
    if (substr)
    {
        printf("Substring: '%s'\n", substr);
        free(substr);
    }
    return 0;
}
*/