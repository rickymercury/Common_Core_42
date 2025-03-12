/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:22:28 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 13:00:35 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = (char *)(s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (last);
}

/* int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("ft_strrchr: %s", ft_strrchr(argv[1], 'o'));
    printf ("\n");
	return (0);
} */