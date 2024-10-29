/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:41 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 22:53:58 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}


/*
int main(void)
{
    t_list *node;
    int *value;

    value = malloc(sizeof(int));
    if (value == NULL)
    {
        printf("Falha na alocação de memória.\n");
        return (1);
    }
    *value = 42;
    node = ft_lstnew(value);
    if (node == NULL)
    {
        printf("Falha na criação do node.\n");
        free(value);
        return (1);
    }
    printf("Conteúdo do node: %d\n", *(int *)node->content);

    free(node->content);
    free(node);

    return (0);
}
*/