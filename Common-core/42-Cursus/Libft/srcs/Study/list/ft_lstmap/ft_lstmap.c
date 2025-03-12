/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:30:52 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/12 12:42:08 by rmedeiro         ###   ########.fr       */
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

    if (!f || !lst)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

/* void *iterate(void *content)
{
    int *num = (int *)content;
    return (num);
}
    
void del_int(void *content)
{
    free(content);
}

int main()
{
    int content1 = 22;
    int content2 = 32;
    int content3 = 42;

    t_list *elem1 = ft_lstnew(&content1);
    t_list *elem2 = ft_lstnew(&content2);
    t_list *elem3 = ft_lstnew(&content3);

    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = NULL;

    t_list *mapped_list = ft_lstmap(elem1, &iterate, &del_int);

    while (mapped_list != NULL)
    {
        printf("%d\n", *(int *)(mapped_list->content));
        mapped_list = mapped_list->next;
    }
    
    ft_lstclear(&elem1, &del_int);
    ft_lstclear(&mapped_list, &del_int);
	free(elem1);
	free(elem2);
	free(elem3);
    return 0;
} */


/*  This is an explanation of the `ft_lstmap` function in C. The purpose of `ft_lstmap` is to create a new
    linked list by applying a given function `f` to the content of each node in the original list, and if necessary,
    freeing the content with a `del` function when an allocation fails.

    According to the manual: "The `ft_lstmap()` function iterates through the given list `lst`, applies the function `f`
    to the content of each node, and creates a new list with the results. If an allocation fails, the new list and its
    contents are cleared by using the function `del`."

    The `ft_lstmap` function performs the following steps:
    
    1. It checks if the list `lst` or the function `f` is `NULL`. If either is `NULL`, it returns `NULL`.
    2. It iterates over the original list, applying `f` to the content of each node and creating a new node with the result.
    3. It adds each new node to a new list (`new_list`).
    4. If memory allocation fails during the iteration, it clears the newly created list using the `del` function to free the
       allocated memory, and then returns `NULL`.
    5. It returns the newly created list.

    Function Parameters:

    - t_list *lst → A pointer to the first node of the list to iterate over.
    - void *(*f)(void*) → A function pointer used to apply a transformation to the content of each node in the original list.
    - void (*del)(void*) → A function pointer used to free the content of each node if an allocation fails during the process.

    Understanding the Implementation:

    The function follows these steps:

    Step 1: Check for NULL List or Function Pointer

        The function starts by checking if either the list (`lst`) or the transformation function (`f`) is `NULL`. If either is
        `NULL`, it returns `NULL` immediately. This avoids any potential null pointer dereferencing.

        if (!f || !lst)
            return (NULL);

    Step 2: Initialize New List

        A new list is initialized to `NULL`. This will hold the new nodes created by applying `f` to the content of each node in
        the original list.

        new_list = NULL;

    Step 3: Iterate Through the Original List

        The function enters a `while` loop, iterating over each node in the original list (`lst`), and processes its content with
        the function `f`. 

        while (lst != NULL)
        {
            node = ft_lstnew(f(lst->content));
            if (node == NULL)
            {
                ft_lstclear(&new_list, del);
                return (NULL);
            }
            ft_lstadd_back(&new_list, node);
            lst = lst->next;
        }

        - For each node, the function applies the transformation `f` to the content of the node (`f(lst->content)`).
        - A new node is created using `ft_lstnew` with the transformed content.
        - If the new node allocation fails (`node == NULL`), the function clears the newly created list by calling `ft_lstclear` and
          uses `del` to free the contents of the new nodes. It then returns `NULL`.
        - If the allocation succeeds, the new node is added to the new list using `ft_lstadd_back`.
        - The loop continues until all nodes in the original list are processed.

    Step 4: Return the New List

        Once the entire list is processed, the function returns the newly created list `new_list`, which contains the transformed content
        from the original list.

        return (new_list);

    
    Handling Edge Cases:

    - **If the list is `NULL` or the function `f` is `NULL`**: The function returns `NULL` immediately.
    - **If memory allocation fails for any new node**: The function clears the already created nodes using `ft_lstclear` and returns `NULL`
      to prevent memory leaks.
    - **Empty List**: If the original list is empty (`lst == NULL`), the function returns `NULL`.

    
    Example Usage:

    void *increment_content(void *content)
    {
        int *new_value = malloc(sizeof(int));
        if (new_value)
        {
            *(int *)new_value = *(int *)content + 1;
        }
        return new_value;
    }

    void del(void *content)
    {
        free(content);
    }
    
    int main(void)
    {
        int *a = malloc(sizeof(int));
        *a = 1;
        int *b = malloc(sizeof(int));
        *b = 2;
        int *c = malloc(sizeof(int));
        *c = 3;

        t_list *head = ft_lstnew(a);
        head->next = ft_lstnew(b);
        head->next->next = ft_lstnew(c);

        printf("Original list:\n");
        t_list *current = head;
        while (current != NULL)
        {
            printf("%d\n", *(int *)current->content);
            current = current->next;
        }

        t_list *new_list = ft_lstmap(head, increment_content, del);

        printf("\nNew list after applying ft_lstmap:\n");
        current = new_list;
        while (current != NULL)
        {
            printf("%d\n", *(int *)current->content);
            current = current->next;
        }
        free(a);
        free(b);
        free(c);
        ft_lstclear(&new_list, del);
        ft_lstclear(&head, del);

        return 0;
    }

    Step-by-Step Execution of the Example:

    Let's walk through an example where we create a linked list, use `ft_lstmap` to transform the content of the nodes, and print the transformed list.

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

        At this point, the original list looks like this:

        head -> node1 -> node2 -> node3 -> NULL
        content: 1 -> 2 -> 3

    Step 2: Define the Transformation Function

        We define a transformation function `increment_content`, which increments the value of each node’s content by 1:

        void *increment_content(void *content)
        {
            int *new_value = malloc(sizeof(int));
            if (new_value)
            {
                *(int *)new_value = *(int *)content + 1;
            }
            return new_value;
        }

    Step 3: Define the Deletion Function

        We define the function `del` to free the content of the nodes in case of an allocation failure:

        void del(void *content)
        {
            free(content);
        }

    Step 4: Call `ft_lstmap`

        Now we call `ft_lstmap`, passing the list `head`, the `increment_content` function, and the `del` function to transform
        the content and create a new list:

        t_list *new_list = ft_lstmap(head, increment_content, del);

    Step 5: Print the Transformed List

        After the transformation, we iterate through the new list and print its content:

        t_list *current = new_list;
        while (current != NULL)
        {
            printf("%d\n", *(int *)current->content);
            current = current->next;
        }

        The expected output will be:

        2
        3
        4

    Step 6: Free the Memory

        Finally, we free all allocated memory to avoid memory leaks:

        free(a);
        free(b);
        free(c);
        ft_lstclear(&new_list, del);

    
    Special Cases:

    - **Empty List (`lst == NULL`)**: The function will return `NULL` immediately.
    - **NULL Function Pointer (`f == NULL`)**: If the transformation function `f` is `NULL`, the function will return `NULL`.
    - **Memory Allocation Failure**: If the memory allocation for any node fails, the function will clear all previously allocated nodes and return `NULL`.

    Key Takeaways:

    - `ft_lstmap` transforms the content of a linked list and creates a new list with the transformed content.
    - The function ensures that the list is not modified during the transformation.
    - Memory is safely managed, and in the case of allocation failure, all previously allocated nodes are freed.
    - The function works well with any transformation function `f`, provided it correctly handles the content type.
*/


/*
TESTER

t_list *ft_lstnew(void *content)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;
    while (*lst)
    {
        tmp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = tmp;
    }
}

void *ft_map(void *ct)
{
    char *c = (char *)ct;
    for (int i = 0; c[i]; i++)
    {
        if (c[i] == 'o')
            c[i] = 'a';
    }
    return c;
}

void ft_del(void *content)
{
    free(content);
}

void ft_print_result(t_list *elem)
{
    int len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, ((char *)elem->content), len);
    write(1, "\n", 1);
}

int main(int argc, const char *argv[])
{
    t_list *elem, *elem2, *elem3, *elem4, *list;
    char *str = strdup("lorem");
    char *str2 = strdup("ipsum");
    char *str3 = strdup("dolor");
    char *str4 = strdup("sit");

    if (argc == 1 || !str || !str2 || !str3 || !str4)
        return 0;

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    elem3 = ft_lstnew(str3);
    elem4 = ft_lstnew(str4);

    if (!elem || !elem2 || !elem3 || !elem4)
        return 0;

    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;

    if (atoi(argv[1]) == 1)
    {
        list = ft_lstmap(elem, &ft_map, &ft_del);
        if (!list)
            return 0;

        ft_print_result(list);
        while (list)
        {
            t_list *tmp = list;
            list = list->next;
            ft_print_result(tmp);
            free(tmp);
        }
    }

    free(str);
    free(str2);
    free(str3);
    free(str4);

    return 0;
}
*/

/*
OUTPUT: 

(CORRECT OUTPUT BUT FSANITIZE SHOW AN ERROR)
cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstmap.c  -o ft_lstmap
sh-5.2$ ./ft_lstmap 1
larem
larem
ipsum
dalar
sit

*/