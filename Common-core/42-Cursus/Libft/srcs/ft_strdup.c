/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 14:38:21 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t  len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (len +1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
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