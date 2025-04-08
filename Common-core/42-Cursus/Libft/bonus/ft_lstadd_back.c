/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:59:19 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/04/09 00:04:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buffer;

	if (!lst || !new)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
}

/* int main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");

	ft_lstadd_back(&list,node1);
	ft_lstadd_back(&list,node2);
	ft_lstadd_back(&list,node3);

	while (list != NULL) 
    {
        printf("%s -> ", (char *)list->content);
        list = list->next;
    }
    printf ("\n");
} */