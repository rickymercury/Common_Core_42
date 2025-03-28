/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:16:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 19:44:45 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if ((size != 0 && nmemb != 0) && nmemb > SIZE_MAX / size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
}

/* int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);

	size_t nmemb = atoi(argv[1]);
	size_t size = atoi(argv[2]);

	char *res_ft_calloc = ft_calloc(nmemb, size);
	char *res_memset = calloc(nmemb, size);

	printf("ft_calloc: %p \n", res_ft_calloc);
	printf("calloc: %p", res_memset);

	free(res_ft_calloc);
	free(res_memset);

	return 0;
} */