/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:22:28 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:15:27 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = (char *)(s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (last);
}

/* int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("ft_strrchr: %s", ft_strrchr(argv[1], 'o'));
    printf ("\n");
	return (0);
} */


/*  This is a recreation of the strrchr function in C. The purpose of strrchr is to locate the last occurrence
    of a given character c in the string s and return a pointer to it.

    According to the manual: "The ft_strrchr() function returns a pointer to the last occurrence of the character
    c in the string s. If the character is not found, the function returns NULL. The terminating null character (\0)
    is considered part of the string, so if c is \0, the function returns a pointer to the null terminator."

    The `ft_strrchr` function searches for the last occurrence of `c` in `s`.
    If `c` is found, it returns a pointer to its position in `s`.
    If `c` is `\0`, it returns a pointer to the string’s null terminator.
    If `c` is not found, it returns `NULL`.

    Function Parameters:

    const char *s → A pointer to the string to be searched.

    int c → The character to find, passed as an int but converted to char.

    Understanding the Implementation:

    The function declares the following variables:

    size_t i → A counter used to iterate through s.

    char *last → A pointer that stores the last occurrence of c found.

    How the function works:

        Initialize Variables:

        i starts at 0 and will iterate through s.

        last is initialized to NULL, meaning no match has been found yet.

        Iterate Through s to Find c:

        The while loop runs as long as s[i] is not \0.

        If s[i] matches c, last is updated to point to s + i.

            while (s[i] != '\0')
            {
                if (s[i] == (char)c)
                    last = (char *)(s + i);
                i++;
            }

        Handle the Null Terminator Case:

        If c is \0, the function returns a pointer to the null terminator.

            if ((char)c == '\0')
                return ((char *)(s + i));

        Return the Last Occurrence or NULL:

        If last was updated, it holds the address of the last occurrence of c.

        If c was not found, last remains NULL and is returned.

            return (last);

    Handling Edge Cases:

    If s is empty (""), the function immediately returns NULL (unless searching for \0).

    If c is \0, the function always returns a pointer to the end of s.

    If c does not appear in s, the function returns NULL.

    Example Usage:

    int main(void)
    {
        char str[] = "Hello, World!";
        char c = 'o';
        char *result = ft_strrchr(str, c);

        if (result)
            printf("Last occurrence of '%c' found at: %s\n", c, result);

        return 0;
    }

    Step-by-Step Execution of the Example:

    Input:

    str = "Hello, World!"
    c = 'o'

    Step 1: Iterating Through the String

    The function scans `str`, updating `last` whenever it finds `c`:

    Index    0   1   2   3   4   5   6   7   8   9   10  11  12  13
    Data     H   e   l   l   o   ,       W   o   r   l   d   !   \0

    - `o` is found at index 4 → `last` is updated to &str[4].
    - `o` is found again at index 8 → `last` is updated to &str[8].

    Step 2: Returning the Result

    The function returns a pointer to `str[8]`, which points to the second 'o' in "World!".

    Output: "Last occurrence of 'o' found at: orld!"

    Special Cases:

    If c is not found:

    ft_strrchr("Hello", 'x') → Returns NULL.

    If c is \0:

    ft_strrchr("Hello", '\0') → Returns a pointer to \0 at the end of "Hello".

    If s is empty:

    ft_strrchr("", 'a') → Returns NULL.

    Key Takeaways:

    ft_strrchr locates the last occurrence of a character in a string.

    It returns a pointer to the last occurrence or NULL if not found.

    It correctly handles \0, empty strings, and non-existent characters.

    It is useful for parsing and searching operations in C.
*/


/*
TESTER

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