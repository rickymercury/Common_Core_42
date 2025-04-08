/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:20:22 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:41:11 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* void ft_itenarate(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
    t_list *head = NULL;
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    node1->content = "Hello";
    node2->content = "World";
    node3->content = "42";

    head = node3;
    node3->next = node2;
    node2->next = node1;
    node1->next = NULL;

    ft_lstiter(head, &ft_itenarate);
    free(node1);
    free(node2);
    free(node3);
}
 */


 /*  This is an explanation of the `ft_lstiter` function in C. The purpose of `ft_lstiter` is to iterate over each node
     in a linked list and apply a given function to the content of each node.

    According to the manual: "The `ft_lstiter()` function iterates through each node of a linked list, applying a given
    function `f` to the content of each node."

    The `ft_lstiter` function performs the following actions:
    
    1. It checks if the provided list pointer (`lst`) is `NULL`. If the list is empty (i.e., `lst == NULL`), the function
       returns immediately without performing any iteration.
    2. It iterates through each node in the list, starting from the head.
    3. It calls the provided function `f` on the content of each node.
    4. It continues iterating until all nodes in the list are processed.

    Function Parameters:

    - t_list *lst → A pointer to the first node of the list.
    - void (*f)(void*) → A function pointer used to apply a function to the content of each node.

    Understanding the Implementation:

    Step 1: Check for NULL List

        The function begins by checking if the provided list (`lst`) is `NULL`. If the list is empty, there is no work to do, so
        the function exits immediately.

        if (!lst)
            return ;

        This ensures that the function does not attempt to iterate over an empty list, avoiding potential errors or unnecessary operations.

        Example:
        
        - If `lst == NULL`, the function returns immediately, and no further processing occurs.

    Step 2: Iterate Through the List

        If the list is not `NULL`, the function enters a `while` loop to iterate through each node in the list. The loop continues as long
        as `lst != NULL`, meaning it will process each node one by one.

        while (lst != NULL)
        {
            (*f)(lst->content);
            lst = lst->next;
        }

        - Inside the loop, the function calls the function `f` on the content of the current node (`lst->content`).
        - The function pointer `f` is expected to be a function that takes a `void*` (a pointer to the content) as an argument and performs some
          action on that content.
        - After calling `f`, the function moves to the next node in the list by setting `lst = lst->next`.

        This process continues until the end of the list is reached (`lst == NULL`), ensuring that every node’s content is processed by the function `f`.

    Step 3: Function Ends

        Once the loop has processed all nodes in the list, the function exits. At this point, all nodes in the list have had the function `f` applied to
        their content.

    Handling Edge Cases:

    - If the list is `NULL`, the function does nothing and returns immediately.
    - If the provided function pointer `f` is `NULL`, the function cannot apply any operation to the content, but the function still iterates through the
      list. However, in practice, a `NULL` function pointer should not be passed, as it would lead to undefined behavior.

    Example Usage:

    void print_content(void *content)
    {
        printf("%d\n", *(int *)content);
    }

    int main(void)
    {
    int *a = malloc(sizeof(int));
    *a = 10;
    int *b = malloc(sizeof(int));
    *b = 20;
    int *c = malloc(sizeof(int));
    *c = 30;

    t_list *head = ft_lstnew(a);
    head->next = ft_lstnew(b);
    head->next->next = ft_lstnew(c);

    printf("Contents of the list:\n");
    ft_lstiter(head, print_content);

    free(a);
    free(b);
    free(c);
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
    
    Step-by-Step Execution of the Example:

    Let's walk through an example usage of the `ft_lstiter` function. In this example, we will create a linked list, and then
    we will use `ft_lstiter` to apply a function to the content of each node.

    Step 1: Create the List

        Before calling `ft_lstiter`, we create a linked list of nodes, each containing an integer.

        int *a = malloc(sizeof(int));
        *a = 10;
        int *b = malloc(sizeof(int));
        *b = 20;
        int *c = malloc(sizeof(int));
        *c = 30;

        t_list *head = ft_lstnew(a);
        head->next = ft_lstnew(b);
        head->next->next = ft_lstnew(c);

        At this point, the list looks like this:

        head -> node1 -> node2 -> node3 -> NULL
        content: 10 -> 20 -> 30

    Step 2: Define the Function to Apply

        We define the function `print_content` that will be applied to each node's content. In this case, the function will print the
        content of each node.

        void print_content(void *content)
        {
            printf("%d\n", *(int *)content);
        }

    Step 3: Call `ft_lstiter(head, print_content)

        Now we call `ft_lstiter` to apply `print_content` to each node's content.

        ft_lstiter(head, print_content);

        Let's break down the execution:
        
        - The function checks if the list is `NULL`. Since the list is not `NULL`, it proceeds to iterate over each node.
        - For each node, the function `print_content` is called with the content of the node.
        - The contents of the nodes are printed one by one:

        10
        20
        30

    Step 4: Verify the Output

        After calling `ft_lstiter`, the content of each node has been processed by the `print_content` function. The output will be:

        10
        20
        30

    
    Special Cases:
    
    - **Empty List (`lst == NULL`)**: If `lst` is `NULL`, the function does nothing and returns immediately.
    - **NULL Function Pointer (`f == NULL`)**: If `f` is `NULL`, the function will still iterate over the list, but no operation will
      be applied to the content of each node. In practice, it’s important not to pass a `NULL` function pointer.
    - **Single Node List**: The function will correctly apply `f` to the single node’s content.

    Key Takeaways:

    - `ft_lstiter` iterates through a linked list and applies a user-defined function to the content of each node.
    - The function does not modify the structure of the list; it only operates on the content of the nodes.
    - The function works on any type of content, as long as the provided function `f` knows how to handle the content type.
    - The function does not return anything, and it modifies the list in no way other than processing the content.
*/


/*
TESTER

void	ft_modify_list_with_d(void *elem)
{
	int		len;
	char		*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		content[len++] = 'd';
	}
}

void	ft_print_result(t_list *elem)
{
	int		len;

	while (elem)
	{
		len = 0;
		while (((char *)elem->content)[len])
			len++;
		write(1, elem->content, len);
		write(1, "\n", 1);
		elem = elem->next;
	}
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

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[1]) == 1)
	{
		ft_lstiter(elem, &ft_modify_list_with_d);
		ft_print_result(elem);
	}

	ft_lstclear(&elem, free);
	
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstiter.c -o ft_lstiter
sh-5.2$ ./ft_lstiter 1
ddddd
ddddd
ddddd
ddd
*/