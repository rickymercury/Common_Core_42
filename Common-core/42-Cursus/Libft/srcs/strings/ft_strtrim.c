/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:45:30 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/08 23:56:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* static int	ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	int		start;
	int		end;
	char	*strimmed;

	start = 0;
	end = (int)ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	strimmed = malloc((end - start + 1) * sizeof(char));
	if (!strimmed)
		return (NULL);
	ft_strlcpy(strimmed, &s1[start], end - start + 1);
	return (strimmed);
} */


static int	is_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int get_end(const char *s1, const char *set)
{
    ssize_t len;

    len = ft_strlen(s1) - 1;
    while (len >= 0)
    {
        if (!is_in_set(set, s1[len]))
            return (len + 1);
        len--;
    }
    return (0);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in_set(set, s1[i]))
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t  start;
    size_t  end;
    size_t  i;
	char 	*str;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
        return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* int main(int argc, char **argv)
{
	// ft_strtrim: Remove os separadores fornecidos de uma str
	// no seu inicio e final.
	if (argc == 3)
	{
		printf("ft_strtrim: %s\n", ft_strtrim(argv[1], argv[2]));
	}
	return (0);
} */

/* 
$ cc -Wall -Werror -Wextra ft_strtrim.c 
$ ./a.out "\\Hello World\\" "\\"
$ ft_strtrim: Hello World 
*/