/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:07:29 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/26 09:07:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

/* void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n > 0)
	{
		*str = (unsigned char) c;
		str++;
		n--;
	}
	return (s);
}
 */
char	*ft_strdup(const char *s)
{
	size_t		size;
	size_t		i;
	char		*dup;

	if (s == NULL)
		return (NULL);
	size = ft_strlen((char *) s) + 1;
	i = 0;
	dup = malloc(size * sizeof(char));
	if (dup == NULL)
		return (NULL);
	size -= 1;
	while (size > i)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}