/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:49 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:46:49 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
        i = 0;
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}


/*
int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[10];
	size_t	length;

	length = ft_strlcpy(dest, src, sizeof(dest));

	printf("SRC: %s\n", src);
	printf("DEST: %s\n", dest);
	printf("SRC LENGTH: %zu\n", length);

	return (0);
}
*/