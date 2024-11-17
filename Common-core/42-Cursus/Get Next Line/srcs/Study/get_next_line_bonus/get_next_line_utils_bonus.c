/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:12:14 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/17 20:25:58 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* 
  This function returns the lenght of the str. 
  Used to discover the lenght of the line to read  */

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/* 
   This function frees the memory pointed to by the pointer str 
   and sets the pointer to NULL to prevent further access to freed memory. */

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

/* Locates the first occurrence of c in the string s */

char *ft_strchr(const char *s, int c)
{
    int i;
    char *str;

    i = 0;
    str = (char *)s;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (str + i);
        i++;
    }
    if ((char)c == '\0')
        return (str + i);
    return (NULL);
}

/* 
   Allocates and returns a new string, which is the concatenation of
   s1 and s2
   This function joins two strings together and returns a new string containing
   the combined strings. */

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

/* 
   Creates a substring of s starting at 'start' with a length of 'len'.
   If 'start' is out of bounds of the string s, it returns an empty string.
   Allocates enough memory for the substring and copies it from s.
   Returns the created substring. */

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start || size == 0)
		len = 0;
	else if (len > size - start)
		len = size - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}