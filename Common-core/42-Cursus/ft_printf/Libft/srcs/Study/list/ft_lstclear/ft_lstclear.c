/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:08:01 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/06 14:46:57 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;

    if (!lst || !*lst)
        return;
    while (*lst)
    {
        temp = (*lst)->next;
        del((*lst)->content);
        free(*lst);            
        *lst = temp;         
    }
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

void ft_print_result(t_list *elem)
{
    if (elem && elem->content)
        write(1, elem->content, strlen(elem->content));
    else
        write(1, "NULL", 4);
}

static int nb_free_done = 0;

void ft_del(void *content)
{
    free(content);
    nb_free_done++;
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
        return 0;

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (!elem || !elem2 || !elem3 || !elem4)
        return 0;

    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;

    nb_free_done = 0;

    if (argc == 2 && atoi(argv[1]) == 1)
    {
        ft_print_result(elem);
        write(1, "\n", 1);

        ft_print_result(elem2);
        write(1, "\n", 1);

        ft_print_result(elem3);
        write(1, "\n", 1);

        ft_print_result(elem4);
        write(1, "\n", 1);

        ft_lstclear(&elem, &ft_del);

        printf("nb_free_done = %d", nb_free_done);
    }

    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstclear.c -o ft_lstclear
sh-5.2$ ./ft_lstclear 1
lorem
ipsum
dolor
sit
nb_free_done = 4
*/