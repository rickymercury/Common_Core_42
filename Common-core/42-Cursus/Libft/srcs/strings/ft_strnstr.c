/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:39:32 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/08 23:56:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *) big);
	if (ft_strlen(little) > len)
		return (NULL);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/* int main(int argc, char **argv)
{
    if (argc == 4)
    {
        char *result_ft = ft_strnstr(argv[1], argv[2], atoi(argv[3]));

        if (result_ft != NULL)
            printf("ft_strnstr: %s\n", result_ft);
    }
    return (0);
} */