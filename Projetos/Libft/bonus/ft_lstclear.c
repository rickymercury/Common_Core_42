/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:08:01 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 22:24:02 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{	
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
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

void	del(void *content)
{
	free(content);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*list = NULL;

	ft_lstadd_front(&list, ft_lstnew(strdup("Benfica")));
	ft_lstadd_front(&list, ft_lstnew(strdup("Queen")));
	ft_lstadd_front(&list, ft_lstnew(strdup("Beatles")));

	ft_lstclear(&list, del);

	if (list == NULL)
		printf("A lista foi limpa com sucesso.\n");
	else
		printf("A lista ainda contém elementos.\n");

	return (0);
}
*/