/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 17:50:01 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
void ft_print_result(int n)
{
    if (n > 0)
        write(1, "1", 1);
    else if (n < 0)
        write(1, "-1", 2);
    else
        write(1, "0", 1);
}

int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return 0;

    if ((arg = atoi(argv[1])) == 1) {
        write(1, "Comparing \"salut\" with \"salut\": ", 33);
        ft_print_result(ft_strncmp("salut", "salut", 5));
        write(1, "\n", 1);
    }
    else if (arg == 2) {
        write(1, "Comparing \"test\" with \"testss\": ", 33);
        ft_print_result(ft_strncmp("test", "testss", 7));
        write(1, "\n", 1);
    }
    else if (arg == 3) {
        write(1, "Comparing \"testss\" with \"test\": ", 33);
        ft_print_result(ft_strncmp("testss", "test", 7));
        write(1, "\n", 1);
    }
    else if (arg == 4) {
        write(1, "Comparing \"test\" with \"tEst\": ", 31);
        ft_print_result(ft_strncmp("test", "tEst", 4));
        write(1, "\n", 1);
    }
    else if (arg == 5) {
        write(1, "Comparing empty string with \"test\": ", 37);
        ft_print_result(ft_strncmp("", "test", 4));
        write(1, "\n", 1);
    }
    else if (arg == 6) {
        write(1, "Comparing \"test\" with empty string: ", 37);
        ft_print_result(ft_strncmp("test", "", 4));
        write(1, "\n", 1);
    }
    else if (arg == 7) {
        write(1, "Comparing \"abcdefghij\" with \"abcdefgxyz\": ", 43);
        ft_print_result(ft_strncmp("abcdefghij", "abcdefgxyz", 3));
        write(1, "\n", 1);
    }
    else if (arg == 8) {
        write(1, "Comparing \"abcdefgh\" with \"abcdwxyz\": ", 39);
        ft_print_result(ft_strncmp("abcdefgh", "abcdwxyz", 4));
        write(1, "\n", 1);
    }
    else if (arg == 9) {
        write(1, "Comparing \"zyxbcdefgh\" with \"abcdwxyz\": ", 41);
        ft_print_result(ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
        write(1, "\n", 1);
    }
    else if (arg == 10) {
        write(1, "Comparing \"abcdefgh\" with empty string: ", 41);
        ft_print_result(ft_strncmp("abcdefgh", "", 0));
        write(1, "\n", 1);
    }
    else if (arg == 11) {
        write(1, "Comparing \"test\\200\" with \"test\\0\": ", 37);
        ft_print_result(ft_strncmp("test\200", "test\0", 6));
        write(1, "\n", 1);
    }

    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strncmp.c -o ft_strncmp && for i in {1..11}; do ./ft_strncmp $i; done
Comparing "salut" with "salut": 0
Comparing "test" with "testss": -1
Comparing "testss" with "test": 1
Comparing "test" with "tEst": 1
Comparing empty string with "test": -1
Comparing "test" with empty string: 1
Comparing "abcdefghij" with "abcdefgxyz": 0
Comparing "abcdefgh" with "abcdwxyz": 0
Comparing "zyxbcdefgh" with "abcdwxyz": 0
Comparing "abcdefgh" with empty string: 0
Comparing "test\200" with "test\0": 1
*/