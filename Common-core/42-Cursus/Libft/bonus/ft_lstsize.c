/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:03:41 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 00:05:49 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*buffer;

	if (lst == NULL)
		return (0);
	i = 0;
	buffer = lst;
	while (buffer != NULL)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

/* int main()
{
	t_list *head = NULL;
	char *cont1 = "Hello";
	char *cont2 = "World";
	char *cont3 = "42";
	int list_size;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));
	node1->content = cont1;
	node2->content = cont2;
	node3->content = cont3;
	
	head = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;
	list_size = ft_lstsize(head);
	printf("Size: %d\n", list_size);

	free(node1);
	free(node2);
	free(node3);
} */