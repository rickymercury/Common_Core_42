/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:57:22 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:38:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*buffer;

	if (lst == NULL)
		return (0);
	i = 0;
	buffer = lst;
	while (buffer != NULL)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

/* int main()
{
	t_list *head = NULL;
	char *cont1 = "Hello";
	char *cont2 = "World";
	char *cont3 = "42";
	int list_size;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));
	node1->content = cont1;
	node2->content = cont2;
	node3->content = cont3;
	
	head = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;
	list_size = ft_lstsize(head);
	printf("Size: %d\n", list_size);

	free(node1);
	free(node2);
	free(node3);
} */



/*  This is an explanation of the `ft_lstsize` function in C. The purpose of `ft_lstsize` is to calculate
    and return the number of nodes in a linked list.

    According to the manual: "The `ft_lstsize()` function takes the address of the first node in the list
    and iterates through the list to count the number of nodes. It then returns the count."

    The `ft_lstsize` function performs the following steps:

    1. It checks if the list (`lst`) is `NULL`. If the list is empty (i.e., `lst == NULL`), it returns 0
       because there are no nodes to count.
    2. It initializes a counter variable `i` to 0 and a temporary pointer `buffer` to traverse the list.
    3. It enters a `while` loop, which continues as long as `buffer` is not `NULL`. During each iteration,
       it moves the `buffer` pointer to the next node and increments the counter `i`.
    4. Once `buffer` reaches `NULL` (i.e., the end of the list is reached), it returns the count of nodes stored in `i`.

    Function Parameters:

    - t_list *lst → A pointer to the first node in the list whose size is to be determined.

    Understanding the Implementation:

    Step 1: Check if the List is Empty

        The function starts by checking if the list (`lst`) is `NULL`. If the list is empty, it returns 0 because there are
        no nodes to count.

        if (lst == NULL)
            return (0);

    Step 2: Initialize Counter and Temporary Pointer

        If the list is not empty, a counter variable `i` is initialized to 0. This variable will keep track of the number of
        nodes in the list.
        A temporary pointer `buffer` is set to the beginning of the list (`lst`). The pointer `buffer` will be used to traverse
        the list.

        i = 0;
        buffer = lst;

    Step 3: Traverse the List

        The function enters a `while` loop to traverse the list. The loop continues as long as `buffer` is not `NULL`, meaning
        there are more nodes to process. For each node, `buffer` is updated to point to the next node (`buffer = buffer->next`),
        and the counter `i` is incremented.

        while (buffer != NULL)
        {
            buffer = buffer->next;
            i++;
        }

    Step 4: Return the Node Count

        Once the loop finishes (when `buffer` becomes `NULL`), the function returns the final value of `i`, which represents the
        total number of nodes in the list.

        return (i);

    
    Handling Edge Cases:

    - **Empty List (`lst == NULL`)**: If the list is empty, the function will immediately return 0, indicating there are no nodes.
    - **Single Node List**: If the list contains only one node, the function will return 1 after one iteration of the loop.
    - **Large Lists**: The function will work for lists of any size, as long as the list is properly terminated (i.e., the last
      node's `next` is `NULL`).

    Example Usage:

    Step-by-Step Execution of the Example:

    Let's walk through an example where we create a linked list, use `ft_lstsize` to determine its size, and print the result.

    Step 1: Create the List

        First, we create a linked list with three nodes, each containing an integer:

        int *a = malloc(sizeof(int));
        *a = 1;
        int *b = malloc(sizeof(int));
        *b = 2;
        int *c = malloc(sizeof(int));
        *c = 3;

        t_list *head = ft_lstnew(a);
        head->next = ft_lstnew(b);
        head->next->next = ft_lstnew(c);

        At this point, the list looks like this:

        head -> node1 -> node2 -> node3 -> NULL
        content: 1 -> 2 -> 3

    Step 2: Call `ft_lstsize`

        Now we call `ft_lstsize` to get the size of the list:

        int size = ft_lstsize(head);

    Step 3: Print the Size

        After calling `ft_lstsize`, we print the result:

        printf("The size of the list is: %d\n", size);

        The expected output will be:

        The size of the list is: 3

    Step 4: Free the Memory

        Finally, we free all allocated memory to avoid memory leaks:

        free(a);
        free(b);
        free(c);
        ft_lstclear(&head, del);

    
    Special Cases:

    - **Empty List (`lst == NULL`)**: If `lst` is `NULL`, the function will return 0.
    - **Single Node**: If the list contains only one node, the function will return 1.
    - **List with Multiple Nodes**: The function works for lists of any length, correctly counting the nodes.

    Key Takeaways:

    - `ft_lstsize` efficiently counts the number of nodes in a linked list.
    - It handles empty lists and lists with one or more nodes.
    - The function performs a simple iteration over the list, ensuring accurate results.
    - It is a useful utility for many linked list operations where knowing the size of the list is necessary.
*/


/*
TESTER

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