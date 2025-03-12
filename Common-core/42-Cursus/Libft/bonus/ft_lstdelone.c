/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:09:00 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:35:30 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

/* void    delete_lst(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
		return (1);

	node1->content = strdup("Hello");
	node2->content = strdup("World");
	node3->content = strdup("42");

	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	printf("Before free: %s\n", (char *)node2->content);
	ft_lstdelone(node1, &delete_lst);
	printf("After deleting node1, node3 content: %s\n", (char *)node3->content);

	ft_lstdelone(node2, &delete_lst);
	ft_lstdelone(node3, &delete_lst);

	return (0);
}
 */



/*  This is an explanation of the `ft_lstdelone` function in C. The purpose of `ft_lstdelone` is to delete a single
    node from a linked list and free both the content of the node and the node itself.

    According to the manual: "The `ft_lstdelone()` function deletes and frees a single node in the linked list. The
    function takes a pointer to the node `lst` to delete and a function pointer `del` to free the content of the node."

    The `ft_lstdelone` function performs the following actions:
    
    1. It checks if the provided node (`lst`) or the function pointer (`del`) is `NULL`. If either is `NULL`, the function
       returns immediately without doing anything.
    2. It uses the provided `del` function to free the content of the node.
    3. It frees the node itself, thus removing it from the memory.

    Function Parameters:

    - t_list *lst → A pointer to the node to be deleted.
    - void (*del)(void*) → A function pointer used to free the content of the node.

    Understanding the Implementation:

    Step 1: Check for NULL Pointers

        The function starts by checking if either the `lst` (the node pointer) or the `del` (the function pointer) is `NULL`. 
        If either is `NULL`, the function immediately returns without doing anything to avoid dereferencing invalid pointers
        or trying to call a `NULL` function pointer.

        if (!lst || !del)
            return ;

        This check ensures that the function does not crash or cause undefined behavior when given invalid inputs. 
        If the node is `NULL`, it means there is no node to delete, and if `del` is `NULL`, there is no valid function to free
        the node content.

        Example:
        
        - If `lst == NULL`, there is no node to delete, and the function exits without performing any further action.
        - If `del == NULL`, the function can't proceed with freeing the node's content, so it exits early.

    Step 2: Free the Content of the Node

        Once it is confirmed that both `lst` and `del` are valid, the function proceeds to free the content of the node. 
        This is done using the `del` function pointer, which points to a function that knows how to properly free the node's content. 

        (*del)(lst->content);

        - `lst->content` refers to the actual data stored in the node. For example, if the node contains a dynamically allocated integer,
          `lst->content` would point to that integer.
        - `(*del)(lst->content)` calls the function that `del` points to, passing `lst->content` as the argument. This function is expected
          to free the memory allocated for the content, ensuring there are no memory leaks.

        The `del` function could be something like `free` or any custom function designed to clean up the memory. The important thing is that
        the `del` function knows how to handle the specific type of content stored in the node.

    Step 3: Free the Node Itself

        After the content of the node is freed, the function proceeds to free the node itself, releasing the memory allocated for the node structure.

        free(lst);

        - `free(lst)` deallocates the memory used by the node, ensuring that there is no memory leak for the node structure itself.

        At this point, both the content of the node and the node structure have been freed, and the node is effectively removed from memory.

    Step 4: Function Ends

        After freeing both the content and the node, the function returns, completing the deletion of the node. The caller can no longer access the
        node since it has been deallocated.

    
    Handling Edge Cases:

    - If `lst` is NULL, there is no node to delete, so the function does nothing.
    - If `del` is NULL, content cannot be freed properly, so the function also does nothing.
    - The function will not crash even if the node is at the end of the list or if it has no successors.

    Example Usage:

    t_list *ft_lstnew(void *content);
    void ft_lstdelone(t_list *lst, void (*del)(void *));
    void del_function(void *content);

    void del_function(void *content)
    {
        free(content);
    }

    int main(void)
    {
        int *a = malloc(sizeof(int));
        *a = 10;

        t_list *node = ft_lstnew(a);

        printf("Before deletion: %d\n", *(int *)node->content);
        ft_lstdelone(node, del_function);
        printf("After deletion: %p\n", (void *)node);
    
        return 0;
    }
    
    Step-by-Step Execution of the Example:

    In this example, we will create a single node with dynamically allocated content, then delete the node using `ft_lstdelone`.

    Step 1: Create the Node

        Before calling `ft_lstdelone`, we create a node using `ft_lstnew`. We allocate memory for an integer, set its value, and assign
        it to the content of the node.

        int *a = malloc(sizeof(int));
        *a = 10;

        t_list *node = ft_lstnew(a);

        At this point, the node structure looks like this:

        node -> content: 10 -> next: NULL

        The node holds a pointer to an integer with the value `10`.

    Step 2: Call `ft_lstdelone(node, del_function);

        We then call `ft_lstdelone` to delete the node. The `del_function` is a function that knows how to free the content of the node
        (in this case, the dynamically allocated integer).

        void del_function(void *content)
        {
            free(content);
        }

        ft_lstdelone(node, del_function);

        Let's break down the execution:
        
        - The function checks if `node` and `del_function` are valid. They are, so it proceeds.
        - It calls `del_function(node->content)` to free the dynamically allocated integer (`*a = 10`).
        - After freeing the content, it calls `free(node)` to release the memory for the node structure itself.

        After the node is deleted, it is no longer accessible in memory.

    Step 3: Verify the Node is Deleted

        If we try to print the node's pointer or access its content after deletion, it will be invalid, and the node will have been deallocated.

        printf("After deletion: %p\n", (void *)node);

        The program will output something like `NULL`, indicating that the node has been deleted from memory.

    
    Special Cases:

    - **NULL Node (`lst == NULL`)**: If `lst` is `NULL`, the function does nothing and returns immediately.
    - **NULL Deletion Function (`del == NULL`)**: If `del` is `NULL`, the function cannot properly free the content and does nothing.
    - **Freeing a Node with No Content**: If the content of the node is already `NULL`, the function still frees the node itself, preventing any
      memory leaks related to the node structure.

    Key Takeaways:

    - `ft_lstdelone` is a simple and safe way to delete a single node from a linked list.
    - It ensures that the node's content is freed using a user-defined function pointer `del`.
    - It is important to pass a valid function pointer to properly free the content of the node.
    - The function does not modify the linked list structure beyond freeing the specified node.
*/



/*
TESTER

void	ft_del(void *content)
{
	free(content);
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

void ft_print_result(t_list *elem) 
{
    if (elem && elem->content) 
	{
        write(1, elem->content, strlen((char *)elem->content));
    } else 
	{
        write(1, "NULL", 4);
    }
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
        return 1;

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (argc == 1 || !elem || !elem2 || !elem3 || !elem4) {
        return 0;
    }

    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;

    if (atoi(argv[1]) == 1) {
        ft_lstdelone(elem3, &ft_del);

        if (elem)
            ft_print_result(elem);
        else
            write(1, "NULL", 4);
        write(1, "\n", 1);
        if (elem2)
            ft_print_result(elem2);
        else
            write(1, "NULL", 4);
        write(1, "\n", 1);
        if (elem4)
            ft_print_result(elem4);
        else
            write(1, "NULL", 4);
        write(1, "\n", 1);
    }

    ft_lstdelone(elem, &ft_del);
    ft_lstdelone(elem2, &ft_del);
    ft_lstdelone(elem4, &ft_del);

    return 0;
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstdelone.c -o ft_lstdelone
sh-5.2$ ./ft_lstdelone 1
lorem
ipsum
sit
*/