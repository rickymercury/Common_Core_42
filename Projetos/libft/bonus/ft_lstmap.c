/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:30:52 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 22:54:42 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_string;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_string = ft_lstnew(f(lst->content));
	if (new_string == NULL)
		return (NULL);
	tmp = new_string;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&new_string, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_string);
}


