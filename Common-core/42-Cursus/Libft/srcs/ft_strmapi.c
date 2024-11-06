/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:03 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 19:53:29 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	unsigned int 	slen;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = (ft_strlen(s));
	str = (char *)malloc((slen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
    i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
void ft_print_result(char const *s)
{
	int len = 0;

	while (s[len])
		len++;
	write(1, s, len);
}

char mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int main(int argc, const char *argv[])
{
	char *str;
	char *strmapi;

	str = (char *)malloc(sizeof(*str) * 12);
	if (!str)
	{
		write(2, "Memory allocation failed for str\n", 34);
		return (1);
	}

	if (argc == 1)
	{
		free(str);
		return (0);
	}

	if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		strmapi = ft_strmapi(str, &mapi);

		if (!strmapi)
		{
			write(2, "Memory allocation failed for strmapi\n", 38);
			free(str);
			return (1);
		}

		ft_print_result(strmapi);

		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strlen(strmapi) >= 12)
			ft_print_result("\nString is not null terminated");

		free(strmapi);
	}
	free(str);
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strmapi.c ft_strlen.c -o ft_strmapi && for i in {1..11}; do ./ft_strmapi $i; done

lOrEm IpSuM
*/