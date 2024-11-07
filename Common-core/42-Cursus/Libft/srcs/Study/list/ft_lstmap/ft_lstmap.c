/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:30:52 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/06 22:14:29 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_element = NULL;

    if (lst == NULL || f == NULL || del == NULL)
        return NULL;
    new_list = ft_lstnew(f(lst->content));
    if (new_list == NULL)
        return NULL;
    new_element = new_list;
    lst = lst->next;
    while (lst != NULL)
    {
        new_element->next = ft_lstnew(f(lst->content));
        if (new_element->next == NULL)
        {
            ft_lstclear(&new_list, del);
            return NULL;
        }
        new_element = new_element->next;
        lst = lst->next;
    }

    return new_list;
}

/*
t_list *ft_lstnew(void *content)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;
    while (*lst)
    {
        tmp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = tmp;
    }
}

void *ft_map(void *ct)
{
    char *c = (char *)ct;
    for (int i = 0; c[i]; i++)
    {
        if (c[i] == 'o')
            c[i] = 'a';
    }
    return c;
}

void ft_del(void *content)
{
    free(content);
}

void ft_print_result(t_list *elem)
{
    int len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, ((char *)elem->content), len);
    write(1, "\n", 1);
}

int main(int argc, const char *argv[])
{
    t_list *elem, *elem2, *elem3, *elem4, *list;
    char *str = strdup("lorem");
    char *str2 = strdup("ipsum");
    char *str3 = strdup("dolor");
    char *str4 = strdup("sit");

    if (argc == 1 || !str || !str2 || !str3 || !str4)
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

    if (atoi(argv[1]) == 1)
    {
        list = ft_lstmap(elem, &ft_map, &ft_del);
        if (!list)
            return 0;

        ft_print_result(list);
        while (list)
        {
            t_list *tmp = list;
            list = list->next;
            ft_print_result(tmp);
            free(tmp);
        }
    }

    free(str);
    free(str2);
    free(str3);
    free(str4);

    return 0;
}
*/

/*
OUTPUT: 

(CORRECT OUTPUT BUT FSANITIZE SHOW AN ERROR)
cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstmap.c  -o ft_lstmap
sh-5.2$ ./ft_lstmap 1
larem
larem
ipsum
dalar
sit

*/