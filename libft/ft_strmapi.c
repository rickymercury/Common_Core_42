/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:03 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:48:04 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc((1 + ft_strlen(s)) * sizeof(char));
	if (str == NULL)
		return (NULL);
    i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char my_func(unsigned int i, char c) 
{
    return c + i;
}

int main() 
{
    const char *s = "abcdef";
    char *result = ft_strmapi(s, my_func);

    if (result) 
    {
        printf("Result: %s\n", result);
        free(result);
    } else {
        printf("Failed to allocate memory.\n");
    }
    return 0;
}
*/