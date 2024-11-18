/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:35 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:22:01 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>

void	ft_print_result(int c, int result) 
{
	if (result)
		printf("'%c': 1\n", c);
	else
		printf("'%c': 0\n", c);
}

int	main() 
{
	int	i;

	printf("Caracteres não alfabéticos antes de '0'\n");
	for (i = 0; i <= 47; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	printf("Dígitos de '0' a '9'\n");
	for (i = '0'; i <= '9'; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	printf("Caracteres não alfabéticos entre '9' e 'A'\n");
	for (i = 58; i <= 64; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	printf("Letras maiúsculas de 'A' a 'Z'\n");
	for (i = 'A'; i <= 'Z'; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	printf("Caracteres não alfabéticos entre 'Z' e 'a'\n");
	for (i = 91; i <= 96; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	printf("Letras minúsculas de 'a' a 'z'\n");
	for (i = 'a'; i <= 'z'; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	printf("Caracteres não alfabéticos após 'z'\n");
	for (i = 123; i <= 127; i++)
		ft_print_result(i, ft_isascii(i));
	printf("\n");

	return (0);
}
*/

/* DESCRIPTION: isascii tests an integer value c to determine whether it is the
EBCDIC equivalent of a character belonging to the ASCII character set.

RETURN VALUE: isascii returns 0 if the character is not ASCII, or a nonzero
value if it is ASCII. If the argument does not have a char value, 0 is returned.
*/