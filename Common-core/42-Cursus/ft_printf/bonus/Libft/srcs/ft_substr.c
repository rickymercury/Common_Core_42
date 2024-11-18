/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:50 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 23:33:19 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start || size == 0)
		len = 0;
	else if (len > size - start)
		len = size - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

/*
void ft_print_result(char const *s)
{
    int len;

    len = 0;
    while (s[len])
        len++;
    write(1, s, len);
}

int main(int argc, const char *argv[])
{
    char str[] = "lorem ipsum dolor sit amet";
    char *strsub;
    int arg;

    if (argc == 1)
        return (0);
    else if ((arg = atoi(argv[1])) == 1)
    {
        strsub = ft_substr(str, 0, 10);
        if (!strsub)
            ft_print_result("NULL");
        else
        {
            ft_print_result(strsub);
            free(strsub);
        }
        write(1, "\n", 1);
    }
    else if (arg == 2)
    {
        strsub = ft_substr(str, 7, 10);
        if (!strsub)
            ft_print_result("NULL");
        else
        {
            ft_print_result(strsub);
            free(strsub);
        }
        write(1, "\n", 1);
    }
    else if (arg == 3)
    {
        strsub = ft_substr(str, 7, 0);
        if (!strsub)
            ft_print_result("NULL");
        else
        {
            ft_print_result(strsub);
            free(strsub);
        }
        write(1, "\n", 1);
    }
    else if (arg == 4)
    {
        strsub = ft_substr(str, 0, 0);
        if (!strsub)
            ft_print_result("NULL");
        else
        {
            ft_print_result(strsub);
            free(strsub);
        }
        write(1, "\n", 1);
    }
    else if (arg == 5)
    {
        strsub = ft_substr(str, 400, 20);
        if (!strsub)
            ft_print_result("NULL");
        else
        {
            ft_print_result(strsub);
            free(strsub);
        }
        write(1, "\n", 1);
    }
    return (0);
}
*/

/*
OUTPUT: 

 cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_substr.c ft_strlen.c -o ft_substr && for i in {1..11}; do ./ft_substr $i; done
lorem ipsu
psum dolor



*/