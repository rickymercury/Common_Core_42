/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:02:03 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:40:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");

	ft_lstadd_front(&list,node1);
	ft_lstadd_front(&list,node2);
	ft_lstadd_front(&list,node3);

	while (list != NULL) 
    {
        printf("%s -> ", (char *)list->content);
        list = list->next;
    }
    printf ("\n");
} */


/*  This is a recreation of the lstadd_front function in C. The purpose of lstadd_front is to
    add a new node at the beginning of a linked list.

    According to the manual: "The ft_lstadd_front() function adds the node new at the beginning of the linked
    list lst."

    The `ft_lstadd_front` function modifies the head of the list to point to the new node.
    If either `lst` or `new` is `NULL`, the function does nothing.

    Function Parameters:

    t_list **lst → A pointer to the pointer of the first node in the list.
    t_list *new → The new node to be added at the front of the list.

    Understanding the Implementation:

    The function follows these steps:

    Check for NULL Pointers

        The function first checks if either lst (the pointer to the list) or new (the new node) is NULL.
        If either is NULL, the function does nothing and simply returns.

        if (!lst || !new)
            return;

    Insert the New Node at the Front

        The next pointer of new is set to the current first node of the list (*lst).
        This step ensures that new now points to the previous first node, linking it to the existing list.

        new->next = *lst;

    Update the Head of the List

        The head of the list (*lst) is updated to point to new, making it the new first node.

        *lst = new;


    Handling Edge Cases:

    If lst is NULL, there is no list to modify, so the function does nothing.
    If new is NULL, there is no node to add, so the function does nothing.
    If the list was previously empty (*lst == NULL), new simply becomes the first node.

    
    Example Usage:

    t_list *ft_lstnew(void *content);
    void ft_lstadd_front(t_list **lst, t_list *new);

    int main(void)
    {
        int a = 10, b = 20;
        t_list *head = ft_lstnew(&a);
        t_list *new_node = ft_lstnew(&b);

        printf("Before: Head content = %d\n", *(int *)head->content);
        ft_lstadd_front(&head, new_node);
        printf("After: Head content = %d\n", *(int *)head->content);

        free(head->next);
        free(head);
        return 0;
    }

    Step-by-Step Execution of the Example:

    Step 1: Create the List

        Two nodes are created:

        head holds 10.
        new_node holds 20.

        Initially, the list is:

        head -> NULL  (content: 10)

    Step 2: Call ft_lstadd_front(&head, new_node);

        new_node->next is set to head (the previous first node).
        head is updated to new_node, making it the new first node.

        The updated list is:

        new_node -> head -> NULL  (content: 20 -> 10)

    Step 3: Print the New Head Content

        The output before the function call:

        Before: Head content = 10

        The output after the function call:

        After: Head content = 20

    Step 4: Free the Allocated Memory

        The nodes are freed to prevent memory leaks.

    
    Special Cases:

    Empty List (*lst == NULL): The function correctly sets *lst to new, making it the only node.

    Adding to a Non-Empty List: The new node is inserted at the beginning, shifting the old first node.


    Key Takeaways:

    ft_lstadd_front efficiently adds a new node to the beginning of a linked list.
    It correctly updates the list's head pointer to the new node.
    It properly handles cases where the list is empty.
    The function does not return anything but modifies the list in place.
*/

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

	new_node = malloc(sizeof(t_list));
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