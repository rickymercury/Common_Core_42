/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 23:02:01 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int size;
	int i;

	size = ft_strlen(s) + 1;
	i = 0;
	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
void	ft_print_result(char const *s)
{
	int		len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	*str;
	char	*str_dup;

	if (argc == 1)
		return (0);

	if (atoi(argv[1]) == 1)
	{
		str = "lorem ipsum dolor sit amet";
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str_dup);
			free(str_dup);
		}
		ft_print_result("\n\n");
	}
	else if (atoi(argv[1]) == 2)
	{
		str = "abc";
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str_dup);
			free(str_dup);
		}
		ft_print_result("\n\n");
	}
	else if (atoi(argv[1]) == 4)
	{
		str = "1234!@#$%^&*()";
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str_dup);
			free(str_dup);
		}
		ft_print_result("\n\n");
	}
	else if (atoi(argv[1]) == 6)
	{
		str = "A";
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str_dup);
			free(str_dup);
		}
		ft_print_result("\n\n");
	}

	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strdup.c ft_strlen.c -o ft_strdup && for i in {1..6}; do ./ft_strdup $i; done

lorem ipsum dolor sit amet

abc

1234!@#$%^&*()

A

*/