/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:20:22 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 22:32:37 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
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

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *node1 = ft_lstnew(strdup("Benfica"));
	t_list *node2 = ft_lstnew(strdup("Queen"));
	t_list *node3 = ft_lstnew(strdup("Beatles"));
	node1->next = node2;
	node2->next = node3;

	printf("Conteúdo da lista:\n");
	ft_lstiter(node1, print_content);

	free(node1->content);
	free(node1);
	free(node2->content);
	free(node2);
	free(node3->content);
	free(node3);

	return (0);
}
*/