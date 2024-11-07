<h1 align="center">Libft</h1>
<p align="center"> 

<h3>
  <p align="center"> 
    <a href="#introduction">Introduction</a> • 
    <a href="#Docs">Docs</a> • 
    <a href="#Compilation">Compilation</a> • 
  </p>
</h3>

## 🗣️ Introduction <a id="introduction"></a>

This repository hosts a custom C library known as Libft, which was implemented as part of a coding project. The primary objective of this project is to develop a static library (.a file) by reimplementing a variety of standard C library functions, as well as adding a few additional, useful functions that enhance the functionality of the C programming language.

A static library is essentially a collection of precompiled object files (.o files) bundled together. These object files are linked directly into the final executable during the compilation process, meaning the functions from the static library become part of the executable itself. This process contrasts with dynamic libraries, which are linked at runtime.

The main goal of this project is twofold. First, it aims to provide a deeper understanding of how commonly used standard library functions are implemented at a lower level. By manually implementing these functions, the programmer gains insight into how things like memory management, string manipulation, and other core operations work under the hood. Second, the library serves as a versatile tool that can be reused across various C projects, eliminating the need for relying on external dependencies or standard library functions in certain contexts.

## 🧬 Libft Structure <a id="structure"></a>

The mandatory part of this project focuses on reimplementing several core functions from the standard C library. These functions are organized into distinct subcategories, each based on their specific purpose and functionality. The primary categories include Libc functions and Additional functions.

    Libc functions: These are the reimplementations of the standard C library functions, which are fundamental to many C programs. The goal is to manually recreate these commonly used functions to gain a deeper understanding of their inner workings and behavior.

    Additional functions: These are utility functions that are not part of the standard C library but are added to complement the existing set of functions. These functions aim to provide helpful features that enhance the library's versatility.

Within these two main categories, the functions are further organized into more specific groups based on the type of operation they perform. These groups include:

    String functions: Functions that manipulate and handle strings, such as string length calculation, copying, concatenation, and comparison.
    Memory functions: Functions dedicated to memory allocation, deallocation, and manipulation, such as memory setting, copying, and freeing.
    Utility functions: A collection of general-purpose functions that provide useful operations, such as type conversions, mathematical computations, and handling specific characters.
    Linked list functions: Functions that operate on linked lists, a common data structure in C, which include operations like creating, traversing, and manipulating linked list nodes.

By categorizing the functions in this way, the project ensures that each function is reimplemented with a specific purpose and is organized logically, making the library more efficient, modular, and easy to use in future projects.


## Directory Tree 

<pre>
Libft
├
├── includes
│   └── libft.h
├── Makefile
├── bonus
|   ├── ft_lstadd_back.c
|   ├── ft_lstadd_front.c
|   ├── ft_lstclear.c
|   ├── ft_lstdelone.c
|   ├── ft_lstiter.c
|   ├── ft_lstlast.c
|   ├── ft_lstmap.c
|   ├── ft_lstnew.c
|   └── ft_lstsize.c
|
└── srcs
    ├── ft_atoi.c
    ├── ft_bzero.c
    ├── ft_calloc.c
    ├── ft_isalnum.c
    ├── ft_isalpha.c
    ├── ft_isascii.c
    ├── ft_isdigit.c
    ├── ft_isprint.c
    ├── ft_itoa.c
    ├── ft_memchr.c
    ├── ft_memcmp.c
    ├── ft_memcpy.c
    ├── ft_memmove.c
    ├── ft_memset.c
    ├── ft_putchar_fd.c
    ├── ft_putendl_fd.c
    ├── ft_putnbr_fd.c
    ├── ft_putstr_fd.c
    ├── ft_split.c
    ├── ft_strchr.c
    ├── ft_strdup.c
    ├── ft_striteri.c
    ├── ft_strjoin.c
    ├── ft_strlcat.c
    ├── ft_strlcpy.c
    ├── ft_strlen.c
    ├── ft_strmapi.c
    ├── ft_strncmp.c
    ├── ft_strnstr.c
    ├── ft_strrchr.c
    ├── ft_strtrim.c
    ├── ft_substr.c
    ├── ft_tolower.c
    └── ft_toupper.c
</pre>
  
> `/includes`: This directory contains the project header file.  
> `/srcs`: This directory contains the project's source code files. 
> `/bonus`: This directory contains the project's bonus code files. 


### String Functions

The **String functions** category encompasses a variety of operations that are essential for handling and manipulating strings in C. These functions are focused on tasks such as calculating string length, copying, concatenating, and searching for specific characters or substrings within a string.

Reimplemented C standard library functions: 

Several core functions from the C standard library are reimplemented to handle common string operations, including:

- [ft_strlen](URL_DA_FUNCAO): Computes the length of a string, excluding the null-terminating character.
- [ft_strlcpy](URL_DA_FUNCAO): Copies a specified number of characters from one string to another, ensuring the destination string is null-terminated.
- [ft_strlcat](URL_DA_FUNCAO): Appends a specified number of characters from one string to the end of another string, ensuring null-termination.
- [ft_strchr](URL_DA_FUNCAO): Searches for the first occurrence of a given character in a string.
- [ft_strrchr](URL_DA_FUNCAO): Searches for the last occurrence of a given character in a string.
- [ft_strncmp](URL_DA_FUNCAO): Compares a specified number of characters between two strings to check for equality.
- [ft_strnstr](URL_DA_FUNCAO): Searches for the first occurrence of a substring within a string, up to a specified length.
- [ft_strdup](URL_DA_FUNCAO): Creates a new string that is a duplicate of an existing string.

Additional String functions: 

These functions extend the functionality of string manipulation by offering more advanced operations that are not typically found in the standard C library:

- [ft_substr](URL_DA_FUNCAO): Creates a new substring from a given string, starting at a specified position and of a specified length.
- [ft_strjoin](URL_DA_FUNCAO): Joins two strings together into a new string.
- [ft_strtrim](URL_DA_FUNCAO): Removes specified characters from the beginning and end of a string.
- [ft_split](URL_DA_FUNCAO): Splits a string into an array of substrings based on a specified delimiter.
- [ft_strmapi](URL_DA_FUNCAO): Applies a function to each character in a string, returning a new string with the results of the function applied.
- [ft_striteri](URL_DA_FUNCAO): Similar to `ft_strmapi`, this function applies a function to each character of a string, but the function receives both the index and the character, allowing for more complex operations.

These functions provide a comprehensive toolkit for string manipulation, ensuring that tasks such as substring extraction, joining, trimming, and splitting can be performed with ease and flexibility.


### Memory Functions

The **Memory functions** category is focused on operations that manipulate raw memory blocks, performing tasks such as setting values, copying, comparing, and allocating memory. These functions are essential for low-level memory management, which is a crucial aspect of systems programming in C.

Reimplemented C standard library functions:

This category includes several key functions that are commonly used in C for handling memory:

- [ft_memset](URL_DA_FUNCAO): Fills a specified number of bytes in a memory block with a given value.
- [ft_bzero](URL_DA_FUNCAO): Sets all bytes in a memory block to zero, effectively clearing the memory.
- [ft_memcpy](URL_DA_FUNCAO): Copies a specified number of bytes from one memory block to another.
- [ft_memmove](URL_DA_FUNCAO): Similar to `ft_memcpy`, but handles overlapping memory areas by ensuring the source is safely moved to the destination.
- [ft_memchr](URL_DA_FUNCAO): Searches for the first occurrence of a specified byte in a memory block.
- [ft_memcmp](URL_DA_FUNCAO): Compares two memory blocks byte-by-byte, up to a specified number of bytes, to determine their equality.
- [ft_calloc](URL_DA_FUNCAO): Allocates memory for an array of a specified number of elements, initializing the memory to zero.

These functions are all designed to operate on raw memory and are often used for operations where the content or structure of the memory is not as important as the underlying bytes themselves. They allow for efficient memory manipulation, which is necessary for tasks like buffer handling and memory clearing.

Memory Allocation and Initialization:

The [ft_calloc](URL_DA_FUNCAO) function is particularly important as it not only allocates memory but also initializes it to zero, which is useful for preventing the use of uninitialized memory.

Together, these memory functions cover common memory manipulation tasks while ensuring safety and efficiency, particularly when dealing with raw memory operations, allocation, and initialization.


### Utility Functions

The **Utility functions** category encompasses a variety of functions that perform operations on characters, strings, and data conversions. These functions are essential for handling common tasks related to character classification, manipulation, and input/output operations.

Character Classification and Conversion:

- [ft_toupper](URL_DA_FUNCAO) and [ft_tolower](URL_DA_FUNCAO) are used to convert characters to uppercase and lowercase, respectively, based on their ASCII values.
- [ft_atoi](URL_DA_FUNCAO) converts a string representation of an integer to an actual integer. This is useful for parsing input strings that contain numerical values.
- [ft_isalpha](URL_DA_FUNCAO) checks if a character is alphabetic.
- [ft_isdigit](URL_DA_FUNCAO) checks if a character is a digit.
- [ft_isalnum](URL_DA_FUNCAO) checks if a character is alphanumeric (either a letter or a digit).
- [ft_isascii](URL_DA_FUNCAO) checks if a character is within the ASCII range.
- [ft_isprint](URL_DA_FUNCAO) checks if a character is printable (i.e., not a control character).

These functions allow for efficient handling and validation of individual characters based on common rules, which is especially useful for parsing and processing textual input.

Additional Utility Functions:

- [ft_itoa](URL_DA_FUNCAO): This function converts an integer to a string representation. It is often used when an integer needs to be outputted or stored as a string.

File Descriptor Output Functions: The following functions provide flexibility for outputting data to different file descriptors:

- [ft_putchar_fd](URL_DA_FUNCAO): Writes a single character to the specified file descriptor.
- [ft_putstr_fd](URL_DA_FUNCAO): Writes a string to the specified file descriptor.
- [ft_putendl_fd](URL_DA_FUNCAO): Writes a string followed by a newline to the specified file descriptor.
- [ft_putnbr_fd](URL_DA_FUNCAO): Writes an integer (converted to a string) to the specified file descriptor.

These utility functions provide a range of capabilities for handling characters and string operations, along with offering flexibility for writing to different output streams (such as standard output or files). 


### List Functions (Bonus)

The **List functions** are focused on operations involving linked lists, a fundamental and flexible data structure often used in C programming for dynamic memory management and efficient insertion/deletion of elements. These functions provide the necessary tools to create, manipulate, and traverse these structures.

Linked List Operations:

- [ft_lstnew](URL_DA_FUNCAO): This function creates a new node for the linked list and returns a pointer to it. It's used to initialize a new list or add new elements.
- [ft_lstadd_front](URL_DA_FUNCAO): Adds a new node at the beginning of the list. This operation modifies the head of the list, making it easy to insert elements at the front.
- [ft_lstsize](URL_DA_FUNCAO): Returns the number of nodes in the list. This function is useful for determining the size of the list without having to traverse it manually.
- [ft_lstlast](URL_DA_FUNCAO): Returns the last node in the list. This is useful for operations where the tail of the list is important, such as appending nodes.
- [ft_lstadd_back](URL_DA_FUNCAO): Adds a new node to the end of the list. This is a common operation for growing the list dynamically by adding elements after the current last node.
- [ft_lstdelone](URL_DA_FUNCAO): Deletes a single node from the list, freeing its memory. This function is essential for safely removing elements without causing memory leaks.
- [ft_lstclear](URL_DA_FUNCAO): Clears the entire list by deleting all nodes. This operation ensures that all dynamically allocated memory is freed when the list is no longer needed.
- [ft_lstiter](URL_DA_FUNCAO): Iterates through the list and applies a given function to each element. This function is useful for processing all elements in a list in a uniform manner.
- [ft_lstmap](URL_DA_FUNCAO): Similar to ft_lstiter, this function iterates through the list, but it also applies a function to each element and returns a new list with the modified values. It allows for transformation of a list into a new one based on custom logic.

Linked lists are widely used in various data structures, algorithms, and system-level programming tasks due to their flexibility in terms of dynamic memory allocation and efficient insertion/removal operations. By using these functions, developers can easily work with lists to store and process data in a structured, efficient way.


<p align="center">
<a href="#introduction"> Top ⬆️ </a>• 
<a href="https://github.com/pin3dev/42_Libft/wiki/Libc">Next ➡️</a>
</p>



## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

A `Makefile` is provided to automate the compilation process. The Makefile includes the following rules:

- `all`: Compiles the library (`libft.a`).
- `clean`: Removes object files.
- `fclean`: Removes object files and the library (`libft.a`).
- `re`: Recompiles the entire project.
- `bonus`: Compiles the bonus part of the project.
- `test`: Compiles the bonus part and runs the test written by [@alelievr](https://github.com/alelievr/libft-unit-test)

To compile the library, simply run:
```bash
make
```
This will generate the `libft.a` library, which can be linked in other projects to use all functions.

<!--
To compile the bonus part, use:
```bash
make bonus
```

To compile the bonus part and test, use:
```bash
make test
```
-->

### Basic Usage

To use the **libft** library in your C code, follow the steps below:

1. Include the header in your code:
    ```c
    #include "libft/includes/libft.h"
    ```

2. Compile your code with the library:
    ```bash
    gcc -Wall -Wextra -Werror -o your_exec your_code.c 42_Libft/libft/libft.a
    ```

3. You can now use any `libft` function in your program now!
