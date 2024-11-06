/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:27:22 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/06 15:08:31 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
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

void del(void *content)
{
    free(content);
}

int main(int argc, const char *argv[])
{
    int         i;
    char        *content;
    t_list      *val;
    t_list      *elem;
    t_list      *elem2;
    t_list      *elem3;
    t_list      *elem4;
    char        *str = strdup("lorem");
    char        *str2 = strdup("ipsum");
    char        *str3 = strdup("dolor");
    char        *str4 = strdup("sit");

    if (!str || !str2 || !str3 || !str4)
        return (1);

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
    {
        free(str);
        free(str2);
        free(str3);
        free(str4);
        return (0);
    }
    else if (atoi(argv[1]) == 1)
    {
        elem->next = elem2;
        elem2->next = elem3;
        elem3->next = elem4;

        val = ft_lstlast(elem);
        i = 0;
        content = val->content;
        while (content[i])
            write(1, &(content[i++]), 1);
        write(1, "\n", 1);

        elem->next = NULL;
        val = ft_lstlast(elem);
        content = val->content;
        i = 0;
        while (content[i])
            write(1, &(content[i++]), 1);
        write(1, "\n", 1);

        elem = NULL;
        val = ft_lstlast(elem);
        if (val == NULL)
            write(1, "NULL", 4);
        write(1, "\n", 1);
    }

    ft_lstclear(&elem, del);

    free(str);
    free(str2);
    free(str3);
    free(str4);

    return (0);
}
*/

/*
OUTPUT: 

(CORRECT OUTPUT BUT FSANITIZE SHOW AN ERROR)
cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstlast.c -o ft_lstlast
sh-5.2$ ./ft_lstlast 1
sit
lorem
NULL

*/