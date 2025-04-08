<h1 align="center">Lists</h1>

<p align="center">
<a href="#strings">Strings</a>• 
<a href="#utils">Utils</a>•
<a href="#strings"> Top ⬆️ </a> 
</p>

## `ft_lstnew`

> Description:  
Creates a new element of a linked list. The variable `content` is initialized with the value of the parameter `content`. The `next` pointer is initialized to `NULL`.

| **Signature**        | `t_list *ft_lstnew(void *content);`                                                            |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `content`: The content to store in the new list element.                                         |
| **Return value**     | A newly allocated list element. Returns `NULL` if the allocation fails.                          |
| **Equivalent**       | The C++ `std::list` STL automatically manages memory and pointers for a linked list.             |              

#### **Usage Example:**

```c
t_list *new_node = ft_lstnew("Hello"); // Creates a node with "Hello" content ((char *)new_node->content)
```

#### **Specifics:**

> The returned list element must be freed after use.

```c
free(new_node);
```

---

## `ft_lstadd_front`

> Description:  
Adds the element `new` at the beginning of the list `lst`.

| **Signature**        | `void ft_lstadd_front(t_list **lst, t_list *new);`                                              |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: A pointer to the first element of the list.                                               |
|                      | `new`: The new element to add.                                                                   |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | The C++ `std::list` class has the `.push_front()` method to add elements to the front of the list.|  

#### **Usage Example:**

```c
t_list *head = ft_lstnew("first");
t_list *new_node = ft_lstnew("second");
ft_lstadd_front(&head, new_node); // switches node "head" to node "new_node".
// Now new_node is the head, (second, first).
```

---

## `ft_lstadd_back`

> Description:  
Adds the element `new` at the end of the list `lst`.

| **Signature**        | `void ft_lstadd_back(t_list **lst, t_list *new);`                                               |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: A pointer to the first element of the list.                                               |
|                      | `new`: The new element to add at the end.                                                        |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | The C++ `std::list` class has the `.push_back()` method to add elements to the back of the list. |  

#### **Usage Example:**

```c
t_list *head = ft_lstnew("first");
t_list *new_node = ft_lstnew("second");
ft_lstadd_back(&head, new_node);
// Now new_node is the last of the linked list, (first, second).
t_list *other_node = ft_lstnew("third");
ft_lstadd_back(&head, other_node);
// Now other_node is the last of the linked list, (first, second, third).
```

---

## `ft_lstsize`

> Description:  
Counts the number of elements in a list.

| **Signature**        | `int ft_lstsize(t_list *lst);`                                                                  |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: The beginning of the list.                                                                |
| **Return value**     | The number of elements in the list.                                                              |
| **Equivalent**       | The C++ `std::list` class has the `.size()` method to return the number of elements in the list. |

#### **Usage Example:**

```c
t_list *head = ft_lstnew("first");
ft_lstadd_back(&head, ft_lstnew("second"));
int size = ft_lstsize(head); // Returns 2
```

---

## `ft_lstlast`

> Description:  
Returns the last element of the list.

| **Signature**        | `t_list *ft_lstlast(t_list *lst);`                                                              |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: The beginning of the list.                                                                |
| **Return value**     | The last element of the list. Returns `NULL` if the list is empty.                               |
| **Equivalent**       | The C++ `std::list` class has the `.back()` method to access the last element of the list.      |

#### **Usage Example:**

```c
t_list *head = ft_lstnew("first");
ft_lstadd_back(&head, ft_lstnew("second"));
t_list *last = ft_lstlast(head); // Returns the last node, "second"
```

---

## `ft_lstdelone`

> Description:  
Takes as a parameter an element and frees the memory of the element's content using the function `del` and free the element itself.

| **Signature**        | `void ft_lstdelone(t_list *lst, void (*del)(void *));`                                           |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: The element to free.                                                                      |
|                      | `del`: A function used to free the content of the element.                                        |
| **Return value**     | None.                                                                                            |
| **Equivalent**       |  None.                                                                                            |

#### **Usage Example:**

```c
void del_content(void *content)
{
    free(content);
}

t_list *node = ft_lstnew(strdup("node"));
ft_lstdelone(node, del_content); // Frees the node and its content, removing node from list
```


---

## `ft_lstclear`

> Description:  
Deletes and frees the memory of all the elements in the list starting from `lst` using the function `del` and frees the list itself. Finally, the pointer to the list is set to `NULL`.

| **Signature**        | `void ft_lstclear(t_list **lst, void (*del)(void *));`                                          |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: The address of a pointer to the first element of the list.                                |
|                      | `del`: A function used to free the content of each element.                                      |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | The C++ `std::list` class has the `.clear()` method to remove all elements from the list and free memory. |

#### **Usage Example:**

```c
void del_content(void *content)
{
    free(content);
}

t_list *head = ft_lstnew(strdup("node1"));
ft_lstadd_back(&head, ft_lstnew(strdup("node2")));
ft_lstclear(&head, del_content); // Applies "del" function to each node content int the list, and frees all nodes too
```

---

## `ft_lstiter`

> Description:  
Iterates through the list `lst` and applies the function `f` to the content of each element.

| **Signature**        | `void ft_lstiter(t_list *lst, void (*f)(void *));`                                              |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: The address of a pointer to the first element of the list.                                |
|                      | `f`: The function to apply to the content of each element.                                       |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | The C++ `std::for_each` algorithm can be used to apply a function to each element in a `std::list`.|

#### **Usage Example:**

```c
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

t_list *head = ft_lstnew(strdup("node1"));
ft_lstadd_back(&head, ft_lstnew(strdup("node2")));
ft_lstiter(head, print_content); // Applies "print_content" function to each node int the list, outputs: "node1" "node2"
```

---

## `ft_lstmap`

> Description:  
Iterates through the list `lst` and applies the function `f` to the content of each element, creating a new list resulting from the successive applications of `f`. The `del` function is used to delete the content of an element if necessary.

| **Signature**        | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`                     |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `lst`: A pointer to the first element of the list.                                               |
|                      | `f`: The function to apply to the content of each element.                                       |
|                      | `del`: A function to free the content if necessary.                                              |
| **Return value**     | A new list resulting from the successive applications of `f`, or `NULL` if allocation fails.      |
| **Equivalent**       | The C++ `std::transform` algorithm can be used to apply a function to each element in a `std::list`.|

#### **Usage Example:**

```c
t_list *head = ft_lstnew(strdup("node1"));
ft_lstadd_back(&head, ft_lstnew(strdup("node2")));
t_list *new_list = ft_lstmap(head, toupper, del_content); // Creates new list with nodes "NODE1" "NODE2"
```
---

<p align="center">
<a href="https://github.com/pin3dev/42_Libft/wiki/Libc"> Previous ⬅️ </a>• 
<a href="#strings"> Top ⬆️ </a>
</p>