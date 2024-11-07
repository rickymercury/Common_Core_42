/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:49 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 17:25:45 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
        i = 0;
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
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

int main(int argc, char *argv[]) {
    char *dest = (char *)malloc(15 * sizeof(char));
    const char *src;
    size_t size;
    size_t result;

    if (argc != 2) {
        printf("Usage: %s <test_number>\n", argv[0]);
        free(dest);
        return 1;
    }

    int test = atoi(argv[1]);

    if (test == 1) 
	{
        strcpy(dest, "rrrrrr");
        src = "lorem";
        size = 15;
        result = ft_strlcpy(dest, src, size);
        printf("Test 1: Return Value: %zu\n", result);
        printf("Test 1: Final dest: %s\n", dest);
    }
    else if (test == 2) 
	{
        strcpy(dest, "rrrrrr");
        src = "";
        size = 15;
        result = ft_strlcpy(dest, src, size);
        printf("Test 2: Return Value: %zu\n", result);
        printf("Test 2: Final dest: %s\n", dest);
    }
    else if (test == 3) 
	{
        dest[0] = '\0';
        src = "lorem ipsum";
        size = 15;
        result = ft_strlcpy(dest, src, size);
        printf("Test 3: Return Value: %zu\n", result);
        printf("Test 3: Final dest: %s\n", dest);
    }
    else if (test == 4) 
	{
        strcpy(dest, "rrrrrr");
        src = "lorem ipsum dolor sit amet";
        size = 20;
        result = ft_strlcpy(dest, src, size);
        printf("Test 4: Return Value: %zu\n", result);
        printf("Test 4: Final dest: %s\n", dest);
    }
    else if (test == 5) 
	{
        strcpy(dest, "aaaaaa");
        src = "bbbbbb";
        size = 10;
        result = ft_strlcpy(dest, src, size);
        printf("Test 5: Return Value: %zu\n", result);
        printf("Test 5: Final dest: %s\n", dest);
    }
    else if (test == 6) 
	{
        strcpy(dest, "short");
        src = "longer string";
        size = 15;
        result = ft_strlcpy(dest, src, size);
        printf("Test 6: Return Value: %zu\n", result);
        printf("Test 6: Final dest: %s\n", dest);
    }
    else if (test == 7) 
	{
        strcpy(dest, "filled");
        src = "with data";
        size = 10;
        result = ft_strlcpy(dest, src, size);
        printf("Test 7: Return Value: %zu\n", result);
        printf("Test 7: Final dest: %s\n", dest);
    }
    else if (test == 8) 
	{
        strcpy(dest, "");
        src = "";
        size = 5;
        result = ft_strlcpy(dest, src, size);
        printf("Test 8: Return Value: %zu\n", result);
        printf("Test 8: Final dest: %s\n", dest);
    }
    else if (test == 9) 
	{
        strcpy(dest, "test");
        src = "appending";
        size = 10;
        result = ft_strlcpy(dest, src, size);
        printf("Test 9: Return Value: %zu\n", result);
        printf("Test 9: Final dest: %s\n", dest);
    }
    else
        printf("Invalid test number. Please enter a number between 1 and 9.\n");

    free(dest);
    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strlcpy.c ft_strlen.c -o ft_strlcpy && for i in {1..9}; do ./ft_strlcpy $i; done
Test 1: Return Value: 5
Test 1: Final dest: lorem
Test 2: Return Value: 0
Test 2: Final dest: 
Test 3: Return Value: 11
Test 3: Final dest: lorem ipsum
Test 4: Return Value: 26
Test 4: Final dest: lorem ipsum dolor s
Test 5: Return Value: 6
Test 5: Final dest: bbbbbb
Test 6: Return Value: 13
Test 6: Final dest: longer string
Test 7: Return Value: 9
Test 7: Final dest: with data
Test 8: Return Value: 0
Test 8: Final dest: 
Test 9: Return Value: 9
Test 9: Final dest: appending
*/