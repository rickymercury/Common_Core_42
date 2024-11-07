/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:08 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 13:08:36 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			total_bytes;
	unsigned char	*ptr;

	i = 0;
	total_bytes = count * size;
	ptr = (unsigned char *) malloc(total_bytes);
	if (ptr == NULL)
		return (NULL);
	while (i < total_bytes)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}


/*
int main(void)
{
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr == NULL)
	{
		printf("Erro ao alocar memória\n");
		return (1);
	}
	printf("Teste 1 - Alocação de 5 inteiros:\n");
	for (size_t i = 0; i < 5; i++)
		printf("arr[%zu] = %d\n", i, arr[i]);

	free(arr);

	return (0);
}
*/