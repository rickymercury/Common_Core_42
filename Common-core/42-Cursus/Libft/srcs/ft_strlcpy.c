/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:46:24 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:58:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

    if (!src)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
    if (size == 0)
		return (src_len);
	if (size > 0)
	{
        i = 0;
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/* int main()
{
    char src[] = "Hello, World!";
    char dest[20];
    size_t size = 16;

    size_t result = ft_strlcpy(dest, src, size);
    printf("ft_strlcpy(%s): %s\n", src, dest);
    printf("Length of source string: %zu\n", result);

    return (0);
} */