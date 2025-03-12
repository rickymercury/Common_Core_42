/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:26:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 13:01:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
    if (start + len > str_len)
		len = str_len - start;
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        buffer[i] = s[start + i];
         i++;
    }
    buffer[i] = '\0';
    return (buffer);
}

/* int main(int argc, char **argv)
{
    // ft_substr: extracts a substring from a given string, starting at the index "start" with length "len"
    if (argc == 4)
    {
        char *result = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
        if (result) 
        {
            printf("ft_substr: %s\n", result);
            free(result);
        }
    }
    return (0);
} */