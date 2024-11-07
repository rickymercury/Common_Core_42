/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:45 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 23:18:45 by rickymercur      ###   ########.fr       */
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
int main() 
{
    const char *str = "Hello world! Welcome to the 42 School.";
    char **result;
    int i;

    result = ft_split(str, ' ');

    if (result) 
    {
        for (i = 0; result[i] != NULL; i++) 
        {
            printf("Word %d: %s\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    } 
    else 
        printf("Error splitting the string.\n");

    return (0);
}
*/