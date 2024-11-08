/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:45 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 22:48:54 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	string_length(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	delimiter(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static char	*split_string(char const *s, char c, size_t *start, size_t *end)
{
	size_t	i;
	size_t	j;
	char	*substring;

	*end = *start + delimiter(s + *start, c);
	i = *start;
	j = 0;
	substring = (char *)malloc((*end - *start + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (i < *end)
		substring[j++] = s[i++];
	substring[j] = '\0';
	*start = *end;
	return (substring);
}

char	**free_split(char **split, size_t j)
{
	while (j > 0)
		free (split[--j]);
	free (split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**result;

	i = 0;
	j = 0;
	result = (char **)malloc((string_length(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			result[j++] = split_string(s, c, &start, &i);
			if (!result[j - 1])
				return (free_split(result, j));
		}
		else
			i++;
	}
	result[j] = NULL;
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