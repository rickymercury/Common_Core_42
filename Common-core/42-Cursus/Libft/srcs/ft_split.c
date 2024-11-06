/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:45 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 18:59:18 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static char *get_next_word(char const **s, char c)
{
    char const *start;
    char *word;
    size_t len;

    while (**s == c && **s)
        (*s)++;
    start = *s;
    while (**s && **s != c)
        (*s)++;
    len = *s - start;
    word = (char *)malloc(len + 1);
    if (word == NULL)
        return (NULL);
    ft_strlcpy(word, start, len + 1);
    return (word);
}

char **ft_split(char const *s, char c)
{
    char **result;
    int words;
    int i;

    if (s == NULL)
        return (NULL);
    words = count_words(s, c);
    result = (char **)malloc((words + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);
    i = 0;
    while (i < words)
    {
        result[i] = get_next_word(&s, c);
        if (result[i] == NULL)
        {
            while (i--)
                free(result[i]);
            free(result);
            return (NULL);
        }
        i++;
    }
    result[i] = NULL;
    return (result);
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