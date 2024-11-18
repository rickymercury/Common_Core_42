/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:52:04 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 21:40:10 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
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
    int len;

    len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, elem->content, len);
    write(1, "\n", 1);
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

void free_content(void *content) 
{
    free(content);
}

int main(int argc, const char *argv[]) 
{
    t_list *begin;
    t_list *elem;
    t_list *elem2;
    t_list *elem3;
    t_list *elem4;
    char *str = strdup("lorem");
    char *str2 = strdup("ipsum");
    char *str3 = strdup("dolor");
    char *str4 = strdup("sit");

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
        return (0);
    else if (atoi(argv[1]) == 1) 
	{
        begin = NULL;
        ft_lstadd_back(&begin, elem);
        ft_lstadd_back(&begin, elem2);
        ft_lstadd_back(&begin, elem3);
        ft_lstadd_back(&begin, elem4);

        t_list *current = begin;
        while (current) 
		{
            ft_print_result(current);
            current = current->next;
        }
    }

    ft_lstclear(&begin, free_content);
    return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g ft_lstadd_back.c -o ft_lstadd_back
sh-5.2$ valgrind ./ft_lstadd_back 1
==53862== Memcheck, a memory error detector
==53862== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==53862== Using Valgrind-3.23.0 and LibVEX; rerun with -h for copyright info
==53862== Command: ./ft_lstadd_back 1
==53862== 
lorem
ipsum
dolor
sit
==53862== 
==53862== HEAP SUMMARY:
==53862==     in use at exit: 0 bytes in 0 blocks
==53862==   total heap usage: 8 allocs, 8 frees, 86 bytes allocated
==53862== 
==53862== All heap blocks were freed -- no leaks are possible
==53862== 
==53862== For lists of detected and suppressed errors, rerun with: -s
==53862== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstadd_back.c -o ft_lstadd_back
sh-5.2$ ./ft_lstadd_back 1
lorem
ipsum
dolor
sit
*/


/* SIMPLIER MAIN

int	main(void)
{
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew("Hello"));
	ft_lstadd_back(&list, ft_lstnew("Ladies"));
	ft_lstadd_back(&list, ft_lstnew("Portugal"));

	while (list)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
	return (0);
}*/