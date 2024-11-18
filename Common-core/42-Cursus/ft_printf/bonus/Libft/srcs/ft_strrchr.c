/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:30 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 17:54:47 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
    char    *str;

	i = 0;
    str = (char *)s;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	return (NULL);
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
    char *str;
    char str2[] = "bonjour";
    int arg;

    if (argc == 1)
        return 0;

    if ((arg = atoi(argv[1])) == 1) {
        write(1, "Testing ft_strrchr with 'b' in \"bonjour\": ", 43);
        if (!(str = ft_strrchr(str2, 'b')))
            ft_print_result("NULL");
        else {
            ft_print_result(str);
            if (str != str2)
                ft_print_result("\nReturn value is false");
        }
        write(1, "\n", 1);
    }
    else if (arg == 2) {
        write(1, "Testing ft_strrchr with 'o' in \"bonjour\": ", 43);
        if (!(str = ft_strrchr(str2, 'o')))
            ft_print_result("NULL");
        else {
            ft_print_result(str);
            if (str != str2 + 4)
                ft_print_result("\nReturn value is false");
        }
        write(1, "\n", 1);
    }
    else if (arg == 3) {
        char str3[] = "bonjourno";
        write(1, "Testing ft_strrchr with 'o' in \"bonjourno\": ", 45);
        if (!(str = ft_strrchr(str3, 'o')))
            ft_print_result("NULL");
        else {
            ft_print_result(str);
            if (str != str3 + 8)
                ft_print_result("\nReturn value is false");
        }
        write(1, "\n", 1);
    }
    else if (arg == 4) {
        write(1, "Testing ft_strrchr with 'j' in \"bonjour\": ", 43);
        if (!(str = ft_strrchr(str2, 'j')))
            ft_print_result("NULL");
        else {
            ft_print_result(str);
            if (str != str2 + 3)
                ft_print_result("\nReturn value is false");
        }
        write(1, "\n", 1);
    }
    else if (arg == 5) {
        write(1, "Testing ft_strrchr with 's' in \"bonjour\": ", 43);
        if (!(str = ft_strrchr(str2, 's')))
            ft_print_result("NULL");
        else
            ft_print_result(str);
        write(1, "\n", 1);
    }
    else if (arg == 6) {
        write(1, "Testing ft_strrchr with '\\0' in \"bonjour\": ", 44);
        if (!(str = ft_strrchr(str2, '\0')))
            ft_print_result("NULL");
        else {
            ft_print_result(str);
            if (str != str2 + 7)
                ft_print_result("\nReturn value is false");
        }
        write(1, "\n", 1);
    }
    else if (arg == 7) {
        char str3[] = "";
        write(1, "Testing ft_strrchr with '\\0' in \"\": ", 37);
        if (!(str = ft_strrchr(str3, '\0')))
            ft_print_result("NULL");
        else {
            ft_print_result(str);
            if (str != str3)
                ft_print_result("\nReturn value is false");
        }
        write(1, "\n", 1);
    }
    
    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strrchr.c -o ft_strrchr && for i in {1..11}; do ./ft_strrchr $i; done
Testing ft_strrchr with 'b' in "bonjour": bonjour
Testing ft_strrchr with 'o' in "bonjour": our
Testing ft_strrchr with 'o' in "bonjourno": o
Testing ft_strrchr with 'j' in "bonjour": jour
Testing ft_strrchr with 's' in "bonjour": NULL
Testing ft_strrchr with '\0' in "bonjour": 
Testing ft_strrchr with '\0' in "": 
Testing ft_strrchr with 'b' in "bonjour + 2": NULL
*/