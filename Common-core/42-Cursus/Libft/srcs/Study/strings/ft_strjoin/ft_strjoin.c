/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:31 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 19:27:36 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	size_t			stotal;
	char		*ptr;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	stotal = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((stotal + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
void ft_print_result(char const *s)
{
	int len = 0;

	while (s[len])
		len++;
	write(1, s, len);
}

int main(int argc, const char *argv[])
{
	char s1[] = "lorem ipsum";
	char s2[] = "dolor sit amet";
	char *strjoin;
	int arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
		write(1, "\n", 1);
		free(strjoin);
	}
	else if (arg == 2)
	{
		s1[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
		write(1, "\n", 1);
		free(strjoin);
	}
	else if (arg == 3)
	{
		s2[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
		write(1, "\n", 1);
		free(strjoin);
	}
	else if (arg == 4)
	{
		s1[0] = '\0';
		s2[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
		write(1, "\n", 1);
		free(strjoin);
	}
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strjoin.c ft_strlen.c -o ft_strjoin && for i in {1..11}; do ./ft_strjoin $i; done
lorem ipsumdolor sit amet
dolor sit amet
lorem ipsum

*/