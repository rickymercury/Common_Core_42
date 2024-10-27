/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:43:08 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/27 21:43:09 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;

    ptr = malloc(count * size);
    if (!ptr)
        return NULL;
    ft_bzero(ptr, count * size);
    return ptr;
}

/*
int main(void)
{
	int *arr;
	size_t count = 5;

	arr = (int *)ft_calloc(count, sizeof(int));
	if (arr == NULL)
	{
		printf("Falha na alocação de memória\n");
		return (1);
	}
	printf("Valores do array após calloc:\n");
	for (size_t i = 0; i < count; i++)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
	}
	free(arr);
	return (0);
}
*/
