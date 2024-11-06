/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:57 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 17:32:38 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
void ft_print_result(int n)
{
    char c;

    if (n >= 10)
        ft_print_result(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int argc, const char *argv[])
{
    int arg;

    if (argc == 1)
        return 0;

    if ((arg = atoi(argv[1])) == 1) {
        write(1, "String: \"Hello !\", Length: ", 27);
        ft_print_result(ft_strlen("Hello !"));
        write(1, "\n", 1); // Nova linha após o resultado
    }
    else if (arg == 2) {
        write(1, "String: \"1\", Length: ", 22);
        ft_print_result(ft_strlen("1"));
        write(1, "\n", 1); // Nova linha após o resultado
    }
    else if (arg == 3) {
        write(1, "String: \"loremipsumdolorsitamet\", Length: ", 43);
        ft_print_result(ft_strlen("lorem\tipsum\tdolor\nsit\namet\n"));
        write(1, "\n", 1); // Nova linha após o resultado
    }
    else if (arg == 4) {
        write(1, "String: \"\", Length: ", 21);
        ft_print_result(ft_strlen(""));
        write(1, "\n", 1); // Nova linha após o resultado
    }
    else if (arg == 5) {
        write(1, "String: \"\\n\\n\\f\\r\\t\", Length: ", 31);
        ft_print_result(ft_strlen("\n\n\f\r\t"));
        write(1, "\n", 1); // Nova linha após o resultado
    }
    else if (arg == 6) {
        write(1, "String: \"   \", Length: ", 24);
        ft_print_result(ft_strlen("   "));
        write(1, "\n", 1); // Nova linha após o resultado
    }

    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strlen.c -o ft_strlen && for i in {1..9}; do ./ft_strlen $i; done
String: "Hello !", Length: 7
String: "1", Length: 1
String: "loremipsumdolorsitamet", Length: 27
String: "", Length: 0
String: "\n\n\f\r\t", Length: 5
String: "   ", Length: 3
*/