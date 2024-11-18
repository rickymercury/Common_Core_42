/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:57:22 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 22:06:01 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	t_list(*current);
	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

/*
t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

void free_list(t_list *lst) 
{
    t_list *temp;
    while (lst) 
    {
        temp = lst->next;
        free(lst->content);
        free(lst);
        lst = temp;
    }
}

void free_list_from(t_list *lst) 
{
    if (!lst) return;
    free_list(lst);
}

int main(int argc, const char *argv[]) 
{
    if (argc != 2) 
    {
        write(1, "Argumento ausente ou inválido.\n", 30);
        return 1;
    }

    t_list *elem;
    t_list *head;
    t_list *elem2;
    t_list *elem3;
    t_list *elem4;
    char c;
    char *str = strdup("lorem");
    char *str2 = strdup("ipsum");
    char *str3 = strdup("dolor");
    char *str4 = strdup("sit");

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (!elem || !elem2 || !elem3 || !elem4) 
    {
        free_list_from(elem);
        return 1;
    }

    head = elem;
    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;

    if (atoi(argv[1]) == 1) 
    {
        c = ft_lstsize(elem) + '0';
        write(1, &c, 1);
        write(1, "\n", 1);

        elem->next = NULL;
        c = ft_lstsize(elem) + '0';
        write(1, &c, 1);
        write(1, "\n", 1);

        elem = NULL;
        c = ft_lstsize(elem) + '0';
        write(1, &c, 1);
        write(1, "\n", 1);
    }

    free_list(head);

    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstsize.c -o ft_lstsize
sh-5.2$ ./ft_lstsize 1
4
1
0
*/