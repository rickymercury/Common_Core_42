/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:42 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/04 16:14:38 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	printf("Teste 1: Caracteres não alfabéticos antes de '0'\n");
	for (i = 0; i <= 47; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	printf("Teste 2: Dígitos de '0' a '9'\n");
	for (i = '0'; i <= '9'; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	printf("Teste 3: Caracteres não alfabéticos entre '9' e 'A'\n");
	for (i = 58; i <= 64; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	printf("Teste 4: Letras maiúsculas de 'A' a 'Z'\n");
	for (i = 'A'; i <= 'Z'; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	printf("Teste 5: Caracteres não alfabéticos entre 'Z' e 'a'\n");
	for (i = 91; i <= 96; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	printf("Teste 6: Letras minúsculas de 'a' a 'z'\n");
	for (i = 'a'; i <= 'z'; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	printf("Teste 7: Caracteres não alfabéticos após 'z'\n");
	for (i = 123; i <= 127; i++)
		ft_print_result(i, ft_isdigit(i));
	printf("\n");

	return (0);
}
*/