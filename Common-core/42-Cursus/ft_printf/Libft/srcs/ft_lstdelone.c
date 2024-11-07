/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:09:00 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 23:26:42 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
void	ft_del(void *content)
{
	free(content);
}

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

void ft_print_result(t_list *elem) 
{
    if (elem && elem->content) 
	{
        write(1, elem->content, strlen((char *)elem->content));
    } else 
	{
        write(1, "NULL", 4);
    }
}

int main(int argc, const char *argv[]) 
{
    t_list *elem;
    t_list *elem2;
    t_list *elem3;
    t_list *elem4;
    char *str = strdup("lorem");
    char *str2 = strdup("ipsum");
    char *str3 = strdup("dolor");
    char *str4 = strdup("sit");

    if (!str || !str2 || !str3 || !str4)
        return 1;

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (argc == 1 || !elem || !elem2 || !elem3 || !elem4) {
        return 0;
    }

    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;

    if (atoi(argv[1]) == 1) {
        ft_lstdelone(elem3, &ft_del);

        if (elem)
            ft_print_result(elem);
        else
            write(1, "NULL", 4);
        write(1, "\n", 1);
        if (elem2)
            ft_print_result(elem2);
        else
            write(1, "NULL", 4);
        write(1, "\n", 1);
        if (elem4)
            ft_print_result(elem4);
        else
            write(1, "NULL", 4);
        write(1, "\n", 1);
    }

    ft_lstdelone(elem, &ft_del);
    ft_lstdelone(elem2, &ft_del);
    ft_lstdelone(elem4, &ft_del);

    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstdelone.c -o ft_lstdelone
sh-5.2$ ./ft_lstdelone 1
lorem
ipsum
sit
*/