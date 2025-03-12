/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:08:01 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:34:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{	
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		(*del)(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/* void delete_lst(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
		return (1);

	node1->content = strdup("Hello");
	node2->content = strdup("World");
	node3->content = strdup("42");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("Before free: %s\n", (char *)node2->content);
	ft_lstclear(&node1, &delete_lst);
} */



/*  This is a recreation of the lstclear function in C. The purpose of lstclear is to delete and free all nodes in a linked list.

    According to the manual: "The ft_lstclear() function deletes and frees the given linked list. The function takes as a parameter
    the address of a pointer to a node and frees the memory of that node and all successors, using the function del. Finally, the pointer
    to the list must be set to NULL."

    The `ft_lstclear` function iterates through a linked list, applies a given function (`del`) to free the content of each node, and then
    frees each node itself.
    The function ensures that the list pointer is set to `NULL` after all nodes are freed.
    If `lst` or `del` is `NULL`, the function does nothing.

    Function Parameters:

    t_list **lst → A pointer to the pointer of the first node in the list.
    void (*del)(void*) → A function pointer used to free the content of each node.

    Understanding the Implementation:

    The function follows these steps:

    Check for NULL Pointers

        The function first checks if either lst (the address of the list) or del (the function to free content) is NULL.
        If either is NULL, the function does nothing and simply returns.

        if (!lst || !del)
            return;

    Iterate Through the List and Free Each Node

        The function uses a loop to traverse the list, freeing each node's content using del and then freeing the node itself.
        A temporary pointer (next) is used to store the next node before freeing the current one.

        current = *lst;
        while (current != NULL)
        {
            next = current->next;
            (*del)(current->content);
            free(current);
            current = next;
        }

    Set the List Pointer to NULL

        After all nodes are freed, *lst is set to NULL to indicate that the list is now empty.

        *lst = NULL;


    Handling Edge Cases:

    If lst is NULL, there is no list to modify, so the function does nothing.
    If del is NULL, content cannot be freed properly, so the function does nothing.
    If the list is already empty (*lst == NULL), nothing happens.

    Example Usage:

    t_list *ft_lstnew(void *content);
    void ft_lstclear(t_list **lst, void (*del)(void *));

   void del_function(void *content)
    {
        free(content);
    }

    int main(void)
    {
        int *a = malloc(sizeof(int));
        int *b = malloc(sizeof(int));
        int *c = malloc(sizeof(int));
        *a = 10;
        *b = 20;
        *c = 30;

        t_list *head = ft_lstnew(a);
        head->next = ft_lstnew(b);
        head->next->next = ft_lstnew(c);

        printf("Before clearing list: %d\n", *(int *)head->content);
        ft_lstclear(&head, del_function);
        printf("After clearing list: %p\n", (void *)head);
    
        return 0;
    }

    Step-by-Step Execution of the Example:

    Step 1: Create the List

        Three nodes are created with dynamically allocated integers.

        Initially, the list is:

        head -> node1 -> node2 -> node3 -> NULL  (content: 10 -> 20 -> 30)

    Step 2: Call ft_lstclear(&head, del_function);

        The function iterates through each node:

        Calls del_function(node1->content), frees node1, moves to node2.

        Calls del_function(node2->content), frees node2, moves to node3.

        Calls del_function(node3->content), frees node3, reaches NULL.

        Finally, head is set to NULL.

    Step 3: Verify the List is Cleared

        The program prints NULL (0x0) for head after calling ft_lstclear.


    Special Cases:

    Empty List (*lst == NULL): The function does nothing, and *lst remains NULL.
    Using a Different del Function: If del does not properly free the content, a memory leak may occur.
    Freeing the List Without Freeing Content: If del is NULL, the function does nothing, leading to memory leaks.

    Key Takeaways:

    ft_lstclear safely frees all nodes in a linked list.
    It correctly handles the deletion of node content using a function pointer.
    It properly updates *lst to NULL to indicate the list is empty.
    The function prevents memory leaks when used correctly with a valid del function.
*/

