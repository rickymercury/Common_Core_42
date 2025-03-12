/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:27:22 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:36:34 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buffer;

	if (!lst || !new)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
} */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buffer;

	if (!lst)
		return (NULL);
	buffer = lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	return (buffer);
}

/* int main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");

	ft_lstadd_back(&list,node1);
	ft_lstadd_back(&list,node2);
	ft_lstadd_back(&list,node3);

	t_list *last = ft_lstlast(list);
    printf("last->content: %s\n", (char *)last->content);
} */


/*  This is a recreation of the lstlast function in C. The purpose of lstlast is to return the
 	last node of a linked list.

	According to the manual: "The ft_lstlast() function returns the last node of the linked list lst.
	If lst is NULL, the function returns NULL."

    The `ft_lstlast` function traverses a linked list until it reaches the last node and returns it.
    If the input list is empty (`NULL`), the function simply returns `NULL`.

	Function Parameters:

	t_list *lst → A pointer to the first node of the linked list.

	Understanding the Implementation:

	The function follows these steps:

	Check for an Empty List:

		The function first checks if lst is NULL. If it is, that means the list is empty, and there is no
		last node to return.

		if (!lst)
    		return (NULL);

	Initialize a Pointer to Traverse the List:

		A pointer buffer is created and initialized to lst. This pointer will be used to iterate through the
		list.

		t_list *buffer = lst;

	Traverse the List Until the Last Node:

		The function enters a while loop that continues moving buffer to the next node (buffer = buffer->next)
		until it finds the last node, where buffer->next == NULL.

		while (buffer->next != NULL)
    	buffer = buffer->next;

	Return the Last Node:

		After exiting the loop, buffer points to the last node, which is then returned.

		return (buffer);

	
	Handling Edge Cases:

	If lst is NULL, the function returns NULL immediately.
	If the list contains only one node (lst->next == NULL), the function correctly returns lst itself as the last node.
	If the list is long, the function efficiently traverses it using a while loop.

	Example Usage:

	t_list *ft_lstnew(void *content);
	t_list *ft_lstlast(t_list *lst);

	int main(void)
	{
    	int a = 10, b = 20, c = 30;
    	t_list *node1 = ft_lstnew(&a);
    	t_list *node2 = ft_lstnew(&b);
    	t_list *node3 = ft_lstnew(&c);

    	node1->next = node2;
    	node2->next = node3;
    	node3->next = NULL;

    	t_list *last = ft_lstlast(node1);
    	if (last)
        	printf("Last node content: %d\n", *(int *)last->content);
    	else
        	printf("List is empty.\n");

    	free(node1);
    	free(node2);
    	free(node3);
    
    	return 0;
	}

	Step-by-Step Execution of the Example:

	Step 1: Create a Linked List

		Three nodes are created, each holding an integer (10, 20, and 30).
		The nodes are linked together in sequence:

  		node1 -> node2 -> node3 -> NULL

	Step 2: Call ft_lstlast(node1)

		The function starts at node1 and moves to node2, then node3.
		Since node3->next == NULL, node3 is returned as the last node.

	Step 3: Print the Last Node's Content

		The function returns node3, and its content (30) is printed:
  		Output: Last node content: 30

	Step 4: Free the Allocated Memory

		All nodes are freed to prevent memory leaks.


	Special Cases:

	Empty List (NULL input): If lst is NULL, the function returns NULL.
	Single Node List: If the list contains only one node, the function returns that node.
	Longer Lists: The function efficiently traverses the list until it reaches the last node.


	Key Takeaways:

	ft_lstlast retrieves the last node in a linked list.
	It correctly handles empty lists and single-node lists.
	The function efficiently iterates through the list without unnecessary operations.
	It is useful for operations that require knowledge of the last node, such as appending elements to a list.
*/



/*
TESTER

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