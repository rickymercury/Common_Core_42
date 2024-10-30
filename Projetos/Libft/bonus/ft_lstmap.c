/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:30:52 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/30 22:49:45 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *new_element;

    if (lst == NULL || f == NULL || del == NULL)
        return (NULL);
    new_list = ft_lstnew(f(lst->content));
    if (new_list == NULL)
        return (NULL);
    new_element = new_list;
    lst = lst->next;
    while (lst != NULL)
    {
        new_element->next = ft_lstnew(f(lst->content));
        if (new_element->next == NULL)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        new_element = new_element->next;
        lst = lst->next;
    }
    return (new_list);
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

void *double_value(void *content) 
{
    int *value = malloc(sizeof(int));
    if (value) {
        *value = (*(int *)content) * 2;
    }
    return value;
}

void delete_content(void *content)
{
    free(content);
}

int main(void)
{
    int *value = malloc(sizeof(int));
    *value = 5;
    t_list *original_list = ft_lstnew(value);

    t_list *mapped_list = ft_lstmap(original_list, double_value, delete_content);

    printf("%d\n", *(int *)(mapped_list->content));

    delete_content(original_list->content);
    free(original_list);
    ft_lstclear(&mapped_list, delete_content);

    return 0;
}
*/