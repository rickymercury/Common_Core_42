/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:40:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:57:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
    size_t	len_s1;
	size_t	len_s2;
	size_t		i;
	size_t	    j;

	if (!s1 || !s2)
		return (NULL);
    i = 0;
    j = 0;
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
	buffer = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!buffer)
		return (NULL);
	while (i < len_s1)
	{
		buffer[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}

/* int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Original string: %s\n", argv[1]);
		printf("Original string: %s\n", argv[2]);
		printf("Joined string: %s\n", ft_strjoin(argv[1], argv[2]));
	}
	return (0);
} */