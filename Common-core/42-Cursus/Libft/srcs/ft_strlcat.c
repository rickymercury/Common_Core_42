/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:40 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 17:11:10 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char *argv[]) {
    char dest[100];
    const char *src;
    size_t size;
    size_t result;

    if (argc != 2) {
        printf("Usage: %s <test_number>\n", argv[0]);
        return 1;
    }

    int test = atoi(argv[1]);

    if (test == 1) 
	{
        strcpy(dest, "rrrrrr");
        src = "lorem";
        size = 15;
        result = ft_strlcat(dest, src, size);
        printf("Test 1: Return Value: %zu\n", result);
        printf("Test 1: Final dest: %s\n", dest);
    }
    else if (test == 2) 
	{
        strcpy(dest, "rrrrrr");
        src = "";
        size = 15;
        result = ft_strlcat(dest, src, size);
        printf("Test 2: Return Value: %zu\n", result);
        printf("Test 2: Final dest: %s\n", dest);
    }
    else if (test == 3) 
	{
        dest[0] = '\0';
        src = "lorem ipsum";
        size = 15;
        result = ft_strlcat(dest, src, size);
        printf("Test 3: Return Value: %zu\n", result);
        printf("Test 3: Final dest: %s\n", dest);
    }
    else if (test == 4) 
	{
        strcpy(dest, "rrrrrr");
        src = "lorem ipsum dolor sit amet";
        size = 20;
        result = ft_strlcat(dest, src, size);
        printf("Test 4: Return Value: %zu\n", result);
        printf("Test 4: Final dest: %s\n", dest);
    }
    else if (test == 5) 
	{
        strcpy(dest, "aaaaaa");
        src = "bbbbbb";
        size = 10;
        result = ft_strlcat(dest, src, size);
        printf("Test 5: Return Value: %zu\n", result);
        printf("Test 5: Final dest: %s\n", dest);
    }
    else if (test == 6) 
	{
        strcpy(dest, "short");
        src = "longer string";
        size = 15;
        result = ft_strlcat(dest, src, size);
        printf("Test 6: Return Value: %zu\n", result);
        printf("Test 6: Final dest: %s\n", dest);
    }
    else if (test == 7) 
	{
        strcpy(dest, "filled");
        src = "with data";
        size = 10;
        result = ft_strlcat(dest, src, size);
        printf("Test 7: Return Value: %zu\n", result);
        printf("Test 7: Final dest: %s\n", dest);
    }
    else if (test == 8) 
	{
        strcpy(dest, "");
        src = "";
        size = 5;
        result = ft_strlcat(dest, src, size);
        printf("Test 8: Return Value: %zu\n", result);
        printf("Test 8: Final dest: %s\n", dest);
    }
    else if (test == 9) 
	{
        strcpy(dest, "test");
        src = "appending";
        size = 10;
        result = ft_strlcat(dest, src, size);
        printf("Test 9: Return Value: %zu\n", result);
        printf("Test 9: Final dest: %s\n", dest);
    }
    else
        printf("Invalid test number. Please enter a number between 1 and 9.\n");

    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_strlcat.c ft_strlen.c -o ft_strlcat && for i in {1..9}; do ./ft_strlcat $i; done
Test 1: Return Value: 11
Test 1: Final dest: rrrrrrlorem
Test 2: Return Value: 6
Test 2: Final dest: rrrrrr
Test 3: Return Value: 11
Test 3: Final dest: lorem ipsum
Test 4: Return Value: 32
Test 4: Final dest: rrrrrrlorem ipsum d
Test 5: Return Value: 12
Test 5: Final dest: aaaaaabbb
Test 6: Return Value: 18
Test 6: Final dest: shortlonger st
Test 7: Return Value: 15
Test 7: Final dest: filledwit
Test 8: Return Value: 0
Test 8: Final dest: 
Test 9: Return Value: 13
Test 9: Final dest: testappen
*/