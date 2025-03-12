/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:41 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:38:19 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int main(void)
{
	char *cont1 = "Hello";
	char *cont2 = "World";
	char *cont3 = "42";
	t_list *node1;
	t_list *node2;
	t_list *node3;
	node1 = ft_lstnew((void *)cont1);
	node2 = ft_lstnew((void *)cont2);
	node3 = ft_lstnew((void *)cont3);
	node1->next = node2;
	node2->next = node3;
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node2->content);
	printf("%s\n", (char *)node3->content);
	free(node1);
	free(node2);
	free(node3);
} */


/*  This is a recreation of the lstnew function in C. The purpose of lstnew is to create a new node
 	for a linked list, initializing it with the provided content.
	According to the manual: "The ft_lstnew() function allocates and returns a new node. The member
	content is initialized with the value of the parameter content. The next pointer is initialized to NULL.
	If the allocation fails, the function returns NULL."

	The `ft_lstnew` function creates a new linked list node with `content` as its data.
    Memory for the node is dynamically allocated and must be freed by the user when no longer needed.
    If allocation fails, the function returns `NULL`.

	Function Parameters:

	void *content → A pointer to the content that will be stored in the new node.

	Understanding the Implementation:

	The function follows these steps:

	Allocate Memory for the New Node:

		The function first declares a pointer new_node of type t_list.
		Then, it uses malloc to allocate memory for a single t_list structure.
		The amount of memory allocated is sizeof(t_list), which ensures space for both the content and the next pointer.
		If malloc fails (returns NULL), the function also returns NULL, preventing further execution.

		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
    		return (NULL);

	Initialize the Node Fields:

		After successful allocation, the function initializes the structure fields:
			The content field is set to the value passed as an argument.
			The next field is set to NULL because the new node does not yet point to another node in the list.

		new_node->content = content;
		new_node->next = NULL;

	Return the New Node:

		Finally, the function returns a pointer to the newly created node.

		return (new_node);

	Handling Edge Cases:

		If malloc fails, the function returns NULL.
		The function does not copy the content, only stores the pointer.
		If content is dynamically allocated, it should be freed manually when no longer needed.
		If content is NULL, the function still creates a valid node where content is NULL, allowing flexibility.

	Example Usage:

	t_list *ft_lstnew(void *content);

	int main(void)
	{
    	int value = 42;
    	t_list *node = ft_lstnew(&value);

    	if (node)
    	{
        	printf("Node content: %d\n", *(int *)node->content);
        	free(node); // Free allocated memory
    	}
    	else
        	printf("Error creating node.\n");

    	return 0;
	}

	Step-by-Step Execution of the Example:

	Step 1: Input Data

	A variable value is initialized with 42.
	The function ft_lstnew(&value) is called to create a new node.

	Step 2: Memory Allocation

	malloc(sizeof(t_list)) is executed to allocate memory for the new node.
	If memory allocation fails, ft_lstnew returns NULL and the program prints Error creating node.

	Step 3: Initializing the Node

	The content pointer inside the node is set to point to &value.
	The next pointer is set to NULL since this is a standalone node.

	Step 4: Printing Node Content

	Since content stores a pointer to value, we cast it back to an integer pointer and dereference it to print:

	printf("Node content: %d\n", *(int *)node->content);
	Output: Node content: 42

	Step 5: Freeing the Allocated Memory

	The dynamically allocated memory for node is released using free(node); to prevent memory leaks.

	
	Special Cases:

	If malloc fails: The function returns NULL, and no node is created.
	If content is NULL: The function still creates a valid node where content is NULL.

	Key Takeaways:

	ft_lstnew creates a new linked list node and initializes it with given content.
	It dynamically allocates memory, so the returned node must be freed after use.
	The function does not duplicate the content; it only stores the pointer.
	It correctly handles edge cases, such as NULL content and memory allocation failures.
*/



/*
TESTER

void	ft_print_result(char const *s) 
{
	int		len = 0;

	while (s[len])
		len++;
	write(1, s, len);
}

void	ft_print_result2(int n) {
	char c;

	if (n >= 10)
		ft_print_result2(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_lstclear(t_list **lst, void (*del)(void *)) 
{
	t_list	*temp;

	if (!lst)
		return;
	while (*lst) {
		temp = (*lst)->next;
		if (del && (*lst)->content)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

void	ft_del(void *content) 
{
	if (content != NULL)
		free(content);
}

int main(int argc, const char *argv[]) 
{
	t_list		*elem;
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1) {
		char	str [] = "lorem ipsum dolor sit";

		if (!(elem = ft_lstnew(str)))
			ft_print_result("NULL");
		else {
			if (!(elem->content))
				ft_print_result("NULL");
			else
				ft_print_result(elem->content);
			
			if (!(elem->next)) 
            {
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
			ft_lstclear(&elem, NULL);
		}
	}
	else if (arg == 2) 
    {
		int		i = 42;

		if (!(elem = ft_lstnew(&i)))
			ft_print_result("NULL");
		else {
			if (!(elem->content))
				ft_print_result("NULL");
			else
				ft_print_result2(*(int *)(elem->content));
			
			if (!(elem->next)) 
            {
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
			ft_lstclear(&elem, NULL);
		}
	}
	else if (arg == 3) 
    {
		if (!(elem = ft_lstnew(NULL)))
			ft_print_result("NULL");
		else {
			if (!(elem->content))
				ft_print_result("NULL");
			else
				ft_print_result(elem->content);
			
			if (!(elem->next)) 
            {
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
			ft_lstclear(&elem, NULL);
		}
	}
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstnew.c -o ft_lstnew
sh-5.2$ ./ft_lstnew 1
lorem ipsum dolor sit
NULL
sh-5./ft_lstnew 2
42
NULL
sh-5.2$ ./ft_lstnew 3
NULL
NULL
*/