/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:53:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:59:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
    char	        *buffer;
	unsigned int	      i;
	unsigned int	    len;

	if (!s || !f)
		return (NULL);
    len = 0;
    while (s[len] != '\0')
		len++;
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    i = 0;
	while (i < len)
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/* char function_f_mapi(unsigned int i, char c)
{
        (void)i;
        return(c + 1);
}

int main()
{
    char *str_strmapi = "Hello, World!";
    char *result_strmapi = ft_strmapi(str_strmapi, function_f_mapi);
    
    printf("Origial: %s\n", str_strmapi);
    printf("New: %s\n", result_strmapi);
    free(result_strmapi);
} */