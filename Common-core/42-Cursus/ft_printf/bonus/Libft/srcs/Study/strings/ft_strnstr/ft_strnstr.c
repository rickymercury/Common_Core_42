/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:22 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 17:40:16 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] != '\0' && (i + j) < len && str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}

/*
void ft_print_result(const char *s)
{
    int len = 0;
    
    while (s[len])
        len++;
    write(1, s, len);
}

int main(int argc, const char *argv[])
{
    const char *str;
    int arg;

    if (argc == 1)
        return 0;

    if ((arg = atoi(argv[1])) == 1) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15);
        write(1, "Searching for \"lorem\": ", 24);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 2) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15);
        write(1, "Searching for \"ipsum\": ", 24);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 3) 
    {
        str = ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35);
        write(1, "Searching for \"ipsum\" in a longer string: ", 43);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 4) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "", 10);
        write(1, "Searching for empty string: ", 29);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 5) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30);
        write(1, "Searching for \"ipsumm\": ", 25);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 6) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "dol", 30);
        write(1, "Searching for \"dol\": ", 22);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 7) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30);
        write(1, "Searching for \"consectetur\": ", 30);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 8) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10);
        write(1, "Searching for \"sit\": ", 22);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 9) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
        write(1, "Searching for \"dolor\": ", 24);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }
    else if (arg == 10) 
    {
        str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0);
        write(1, "Searching for \"dolor\" with size 0: ", 36);
        if (!str)
            ft_print_result("NULL\n");
        else {
            ft_print_result(str);
            write(1, "\n", 1);
        }
    }

    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strnstr.c -o ft_strnstr && for i in {1..9}; do ./ft_strnstr $i; done
Searching for "lorem": lorem ipsum dolor sit amet
Searching for "ipsum": ipsum dolor sit amet
Searching for "ipsum" in a longer string: ipsum dolor sit lorem ipsum dolor
Searching for empty string: lorem ipsum dolor sit amet
Searching for "ipsumm": NULL
Searching for "dol": dolor sit amet
Searching for "consectetur": NULL
Searching for "sit": NULL
Searching for "dolor": NULL
*/