/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:45 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:55:18 by rmedeiro         ###   ########.fr       */
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