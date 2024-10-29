/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:48:42 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:48:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(const char *ptr, char c)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int get_end(const char *s1, const char *set)
{
    int len = ft_strlen(s1) - 1;

    while (len >= 0)
    {
        if (!is_char(set, s1[len]))
            return (len + 1);
        len--;
    }
    return (0);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!is_char(set, s1[i]))
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
	char *str;


	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
    if (start >= end)
    {
        return (malloc(1));
    }
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
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

/*
int main(void)
{
    const char *str = "   Hello, World!   ";
    const char *set = " ";
    char *trimmed_str;

    trimmed_str = ft_strtrim(str, set);
    if (trimmed_str)
    {
        printf("Trimmed String: '%s'\n", trimmed_str);
        free(trimmed_str);
    }
    else
    {
        printf("Error allocating memory.\n");
    }

    return 0;
}
*/