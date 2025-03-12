/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:11:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:56:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/* void print_char_index(unsigned int index, char *c)
{
    printf("Index: %u, Char: %c\n", index, *c);
}

int main()
{
    char str[] = "Hello, 42!";

    ft_striteri(str, print_char_index);

    return (0);
} */