/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:41 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 13:13:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* int main(void)
{
	char *cont1 = "Hello";
	char *cont2 = "World";
	char *cont3 = "42";
	t_list *node1;
	t_list *node2;
	t_list *node3;
	node1 = ft_lstnew((void *)cont1);
	node2 = ft_lstnew((void *)cont2);
	node3 = ft_lstnew((void *)cont3);
	node1->next = node2;
	node2->next = node3;
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node2->content);
	printf("%s\n", (char *)node3->content);
	free(node1);
	free(node2);
	free(node3);
} */