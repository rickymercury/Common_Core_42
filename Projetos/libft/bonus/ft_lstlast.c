/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:27:22 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 22:33:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}


/*
t_list	*ft_lstnew(void *content)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	main(void)
{
	t_list *node1 = ft_lstnew(strdup("First node"));
	t_list *node2 = ft_lstnew(strdup("Second node"));
	t_list *node3 = ft_lstnew(strdup("Third node"));
	node1->next = node2;
	node2->next = node3;

	t_list *last_node = ft_lstlast(node1);

	if (last_node != NULL)
		printf("Conteúdo do último node: %s\n", (char *)last_node->content);
	else
		printf("A lista está vazia.\n");

	free(node1->content);
	free(node1);
	free(node2->content);
	free(node2);
	free(node3->content);
	free(node3);

	return (0);
}
*/