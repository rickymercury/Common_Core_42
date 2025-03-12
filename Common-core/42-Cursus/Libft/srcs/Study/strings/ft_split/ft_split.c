/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:45 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:08:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

    if (!src)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
    if (size == 0)
		return (src_len);
	if (size > 0)
	{
        i = 0;
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
} */

static int	countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*wordalloc(char const **s, char c)
{
	char		*word;
	char const	*str;
	int			len;

	len = 0;
	while (**s && **s == c)
		(*s)++;
	str = (*s);
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = countwords(s, c);
	result = malloc(sizeof(char *) * (size + 1));
	result[size] = 0;
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = wordalloc(&s, c);
		if (!result[i])
		{
			while (i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}


/* int	main()
{
	char	**strs;
	int		i;

	strs = ft_split("Hello, World!", ' ');
	i = 0;
	while (strs[i] != NULL)
	{
		printf("ft_split(%s): %s\n", "Hello, World!", strs[i]);
		i++;
	}
	return (0);
} */


/*  This is an explanation of the `ft_split` function and its helper functions, `countwords` and `wordalloc`,
    which are used to split a string into an array of substrings based on a delimiter character.

    `countwords` Function:

    The `countwords` function counts the number of words in the input string `s`, separated by the delimiter character `c`.
    A word is considered to be a sequence of characters that is surrounded by delimiters or the start/end of the string.

    The function follows these steps:

    1. Initialize Counters:
   
    - It starts with `i = 0` and `count = 0`. The counter `i` is used to iterate through the string, while `count` keeps
      track of the number of words found.

    2. Iterate through the String:
    
   - The outer `while (s[i])` loop iterates through each character of the string `s`.

    3. Skip Delimiters:
    
   - If the current character is the delimiter `c`, the inner loop (`while (s[i] == c && s[i])`) is used to skip over all
     consecutive delimiters.

    4. Count Words:
   
    - If the current character is not a delimiter (i.e., a part of a word), the word count is incremented (`count++`), and
      the program proceeds to the next loop to skip over the characters of the word.

    5. Skip Non-Delimiter Characters:
    
   - After counting a word, the program enters another inner loop (`while (s[i] != c && s[i])`) to skip over the characters of
     the current word until it encounters a delimiter or the end of the string.

    6. Return the Word Count:
    
   - Once the entire string has been processed, the function returns the total number of words found.


    'wordalloc' Function:

    The wordalloc function allocates memory for a new word and copies the characters of a word from the input string s. It skips
    leading delimiters and copies characters until it encounters another delimiter or the end of the string.

    The function follows these steps:

    1.Skip Leading Delimiters:
    
        The function uses while(**s && **s == c) to skip any leading delimiters.

    2.Calculate the Word Length:
    
        Once the function finds the beginning of a word, it counts the length of the word by incrementing len until it encounters a
        delimiter or the end of the string.

    3.Allocate Memory for the Word:
    
        The function allocates memory for the word with malloc, ensuring that there is space for the word plus a null terminator (len + 1).

    4.Copy the Word:
    
        The word is copied from the string s to the newly allocated memory using the ft_strlcpy function.

    5.Return the Word:
    
        The function returns a pointer to the newly allocated word.

   
    'ft_split' Function:

    The ft_split function splits the input string s into an array of substrings, using the delimiter c. It first counts the number of words
    using countwords and then allocates memory for each word using wordalloc. The result is a dynamically allocated array of strings, where
    each string is a word from the original input string.

The function follows these steps:

    Check for NULL String:
        If the input string s is NULL, the function returns NULL because there is nothing to split.

    Count the Number of Words:
        The function calls countwords(s, c) to calculate how many words are in the input string s.

    Allocate Memory for the Result Array:
        The function allocates memory for an array of char * pointers, with enough space to store all the words and one additional pointer for the NULL terminator.

    Allocate and Copy Each Word:
        For each word, the function calls wordalloc to allocate memory for the word and copy it from s. It updates the pointer s to point to the next word.

    Handle Memory Allocation Failure:
        If any memory allocation fails (for either a word or the result array), the function frees any previously allocated memory and returns NULL.

    Return the Result Array:
        If all words have been successfully allocated, the function returns the array of substrings (result).

Example Usage of ft_split:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "Hello world this is 42";
    char delimiter = ' ';
    char **result = ft_split(str, delimiter);

    // Print the split result
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]); // Free each word after printing
        }
        free(result); // Free the result array
    }

    return 0;
}

Expected Output:

Word 1: Hello
Word 2: world
Word 3: this
Word 4: is
Word 5: 42

Key Takeaways:

    countwords:
        Efficiently counts the number of words in a string based on a delimiter.
        Handles multiple consecutive delimiters and words at the start/end of the string.

    wordalloc:
        Allocates memory for each word, skipping delimiters and copying characters until the next delimiter or the end of the string is encountered.
        Uses ft_strlcpy to ensure proper string copying with null termination.

    ft_split:
        Splits the string into an array of words using a delimiter.
        Allocates memory for both the words and the array of words, ensuring proper handling of memory allocation failures.
        Frees any previously allocated memory if a failure occurs to prevent memory leaks.

    Memory Management:
        All dynamically allocated memory (words and the result array) should be freed after use to avoid memory leaks.

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
    char **tabstr;
    int i;
    int arg;

    if (argc == 1)
        return (0);
    i = 0;
    if ((arg = atoi(argv[1])) == 1)
    {
        if (!(tabstr = ft_split("          ", ' ')))
            ft_print_result("NULL");
        else
        {
            while (tabstr[i] != NULL)
            {
                ft_print_result(tabstr[i]);
                write(1, "\n", 1);
                i++;
            }
            for (int j = 0; tabstr[j] != NULL; j++)
                free(tabstr[j]);
            free(tabstr);
        }
        write(1, "\n", 1);
    }
    else if (arg == 2)
    {
        if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
            ft_print_result("NULL");
        else
        {
            while (tabstr[i] != NULL)
            {
                ft_print_result(tabstr[i]);
                write(1, "\n", 1);
                i++;
            }
            for (int j = 0; tabstr[j] != NULL; j++)
                free(tabstr[j]);
            free(tabstr);
        }
        write(1, "\n", 1);
    }
    else if (arg == 3)
    {
        if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
            ft_print_result("NULL");
        else
        {
            while (tabstr[i] != NULL)
            {
                ft_print_result(tabstr[i]);
                write(1, "\n", 1);
                i++;
            }
            for (int j = 0; tabstr[j] != NULL; j++)
                free(tabstr[j]);
            free(tabstr);
        }
        write(1, "\n", 1);
    }
    else if (arg == 4)
    {
        if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
            ft_print_result("NULL");
        else
        {
            while (tabstr[i] != NULL)
            {
                ft_print_result(tabstr[i]);
                write(1, "\n", 1);
                i++;
            }
            for (int j = 0; tabstr[j] != NULL; j++)
                free(tabstr[j]);
            free(tabstr);
        }
        write(1, "\n", 1);
    }
    else if (arg == 5)
    {
        if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
            ft_print_result("NULL");
        else
        {
            while (tabstr[i] != NULL)
            {
                ft_print_result(tabstr[i]);
                write(1, "\n", 1);
                i++;
            }
            for (int j = 0; tabstr[j] != NULL; j++)
                free(tabstr[j]);
            free(tabstr);
        }
        write(1, "\n", 1);
    }
 
    return (0);
}
*/

/*
cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_split.c ft_strlcpy.c -o ft_split && for i in {1..11}; do ./ft_split $i; done

lorem
ipsum
dolor
sit
amet,
consectetur
adipiscing
elit.
Sed
non
risus.
Suspendisse

lorem
ipsum
dolor
sit
amet,
consectetur
adipiscing
elit.
Sed
non
risus.
Suspendisse

lorem 
psum dolor s
t amet, consectetur ad
p
sc
ng el
t. Sed non r
sus. Suspend
sse lectus tortor, d
gn
ss
m s
t amet, ad
p
sc
ng nec, ultr
c
es sed, dolor. Cras elementum ultr
c
es d
am. Maecenas l
gula massa, var
us a, semper congue, eu
smod non, m
.

lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.

ok

*/