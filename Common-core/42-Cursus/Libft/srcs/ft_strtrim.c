/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:42 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 20:40:16 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	is_char(const char *ptr, char c)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int get_end(const char *s1, const char *set)
{
    int len = ft_strlen(s1) - 1;

    while (len >= 0)
    {
        if (!is_char(set, s1[len]))
            return (len + 1);
        len--;
    }
    return (0);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!is_char(set, s1[i]))
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t  start;
    size_t  end;
    size_t  i;
	char 	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
	{
		str = malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*
void	ft_print_result(const char *s)
{
	int len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void ft_strtrim_free(char *str) 
{
    free(str);
}

int		main(int argc, const char *argv[])
{
	char	*strtrim;
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		strtrim = ft_strtrim(s1, " ");
		if (!strtrim)
			ft_print_result("NULL");
		else
		{
			ft_print_result(strtrim);
			ft_strtrim_free(strtrim);
		}
		write(1, "\n", 1);
	}
	else if (arg == 2)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		strtrim = ft_strtrim(s1, "te");
		if (!strtrim)
			ft_print_result("NULL");
		else
		{
			ft_print_result(strtrim);
			ft_strtrim_free(strtrim);
		}
		write(1, "\n", 1);
	}
	else if (arg == 3)
	{
		char s1[] = " lorem ipsum dolor sit amet";
		strtrim = ft_strtrim(s1, "l ");
		if (!strtrim)
			ft_print_result("NULL");
		else
		{
			ft_print_result(strtrim);
			ft_strtrim_free(strtrim);
		}
		write(1, "\n", 1);
	}
	else if (arg == 4)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		strtrim = ft_strtrim(s1, "tel");
		if (!strtrim)
			ft_print_result("NULL");
		else
		{
			ft_print_result(strtrim);
			ft_strtrim_free(strtrim);
		}
		write(1, "\n", 1);
	}
	else if (arg == 5)
	{
		char s1[] = "          ";
		strtrim = ft_strtrim(s1, " ");
		if (!strtrim)
			ft_print_result("NULL");
		else
		{
			ft_print_result(strtrim);
			ft_strtrim_free(strtrim);
		}
		write(1, "\n", 1);
	}
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strtrim.c ft_strlen.c -o ft_strtrim && for i in {1..11}; do ./ft_strtrim $i; done

lorem 
 ipsum   dolor 
 sit     amet
lorem ipsum dolor sit am
orem ipsum dolor sit amet
orem ipsum dolor sit am

*/