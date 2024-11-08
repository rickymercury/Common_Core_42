/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:02 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 22:54:06 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    char    *str;

    i = 0;
    str = (char *)s;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (str + i);
        i++;
    }
    if (s[i] != '\0' && (char)c == '\0')
        return (str + i);
    return (NULL);
}

/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char		*str;
	char		str2[] = "bonjour";
	int			arg;

	if (argc == 1)
		return (0);

	arg = atoi(argv[1]);
	if (arg == 1)
	{
		if (!(str = ft_strchr(str2, 'b')))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str);
			if (str != str2)
				ft_print_result("\nReturn value is false");
		}
		ft_print_result("\n");
	}
	else if (arg == 2)
	{
		if (!(str = ft_strchr(str2, 'o')))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str);
			if (str != str2 + 1)
				ft_print_result("\nReturn value is false");
		}
		ft_print_result("\n");
	}
	else if (arg == 3)
	{
		if (!(str = ft_strchr(str2, 'j')))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str);
			if (str != str2 + 3)
				ft_print_result("\nReturn value is false");
		}
		ft_print_result("\n");
	}
	else if (arg == 4)
	{
		if (!(str = ft_strchr(str2, 's')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
		ft_print_result("\n");
	}
	else if (arg == 5)
	{
		if (!(str = ft_strchr(str2, '\0')))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str);
			if (str != str2 + 7)
				ft_print_result("\nReturn value is false");
		}
		ft_print_result("\n");
	}
	else if (arg == 6)
	{
		char	str3[] = "";
		if (!(str = ft_strchr(str3, '\0')))
			ft_print_result("NULL");
		else
		{
			ft_print_result(str);
			if (str != str3)
				ft_print_result("\nReturn value is false");
		}
		ft_print_result("\n");
	}
	return (0);
}
*/


/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strchr.c -o ft_strchr && for i in {1..6}; do ./ft_strchr $i; done
bonjour
onjour
jour
NULL
NULL
NULL
*/