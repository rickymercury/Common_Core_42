/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:02:03 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:42:08 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

/*
void ft_print_result(t_list *elem)
{
    int len;

    len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, elem->content, len);
    write(1, "\n", 1);
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

void ft_lstclear(t_list **lst, void (*del)(void*)) 
{
    t_list *current;
    t_list *next;

    if (lst == NULL || *lst == NULL || del == NULL)
        return;
    current = *lst;
    while (current != NULL) {
        next = current->next;
        del(current->content);
        free(current);
        current = next;
    }
    *lst = NULL;
}

int main(int argc, const char *argv[])
{
    t_list *begin = NULL;
    t_list *elem;
    t_list *elem2;
    t_list *elem3;
    t_list *elem4;
    char *str = strdup("lorem");
    char *str2 = strdup("ipsum");
    char *str3 = strdup("dolor");
    char *str4 = strdup("sit");

    if (!str || !str2 || !str3 || !str4)
    {
        perror("Failed to allocate memory");
        return (1);
    }

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);
    
    if (!elem || !elem2 || !elem3 || !elem4)
    {
        perror("Failed to allocate memory for list elements");
        return (1);
    }
    if (argc == 1)
    {
        write(1, "Usage: ./ft_lstadd_back <number>\n", 34);
        return (0);
    }
    else if (atoi(argv[1]) == 1)
    {
        ft_lstadd_front(&begin, elem4);
        ft_lstadd_front(&begin, elem3);
        ft_lstadd_front(&begin, elem2);
        ft_lstadd_front(&begin, elem);
        
        while (begin)
        {
            ft_print_result(begin);
            begin = begin->next;
        }
    }

    ft_lstclear(&begin, free);
    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstadd_front.c -o ft_lstadd_front
sh-5.2$ ./ft_lstadd_front 1
lorem
ipsum
dolor
sit

*/

/* SIMPLIER MAIN

int	main(void)
{
	t_list *list = NULL;

	ft_lstadd_front(&list, ft_lstnew("Hello"));
	ft_lstadd_front(&list, ft_lstnew("Ladies"));
	ft_lstadd_front(&list, ft_lstnew("Portugal"));

	while (list)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
	return (0);
}*/