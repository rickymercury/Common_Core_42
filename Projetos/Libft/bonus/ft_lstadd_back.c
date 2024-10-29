/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:52:04 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 22:36:44 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
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
	t_list	*list = NULL;

	ft_lstadd_back(&list, ft_lstnew("Primeiro"));
	ft_lstadd_back(&list, ft_lstnew("Segundo"));
	ft_lstadd_back(&list, ft_lstnew("Terceiro"));

	t_list *temp = list;
	while (temp)
	{
		printf("%s -> ", (char *)temp->content);
		temp = temp->next;
	}
	printf("NULL\n");

	temp = list;
	while (temp)
	{
		t_list *next = temp->next;
		free(temp);
		temp = next;
	}

	return (0);
}
*/