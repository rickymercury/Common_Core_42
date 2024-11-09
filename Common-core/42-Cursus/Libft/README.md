<h1 align="center">
<p>
    <a href="#libft" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Libft</a> • 
<p align="center"> 
</p>
</h1>

---

<h3 align="center" style="font-weight: bold; font-size: 1.2em; line-height: 1.5em; color: #333;">
  <p>
    <a href="#intro" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🗣️ Introduction</a> • 
    <a href="#structure" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🧬 Structure</a> • 
    <a href="#functions" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Functions</a> • 
    <a href="#compilation" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Compilation</a>
  </p>
</h3>

---

## 🗣️ **Introduction: Project Overview** <a id="intro"></a>

This repository hosts a custom C library known as **<span style="color:blue">Libft</span>**, which was implemented as part of a coding project. The primary objective of this project is to develop a **static library** (`.a` file) by reimplementing a variety of standard C library functions, as well as adding a few additional, useful functions that enhance the functionality of the C programming language.

---

> **What is a Static Library?**
> 
> A **static library** is essentially a collection of precompiled **object files** (`.o` files) bundled together. These object files are linked directly into the final executable during the compilation process, meaning the functions from the static library become part of the executable itself. This process contrasts with **dynamic libraries**, which are linked at runtime.

---

## ✨ **Project Goals**

The main goal of this project is:

1. **Understanding Standard Library Functions**

   This project provides a deeper understanding of how commonly used standard library functions are implemented at a lower level. By manually implementing these functions, the programmer gains insight into how things like **memory management**, **string manipulation**, and other core operations work under the hood.
   
2. **Reusable Tool for C Projects**  

   The library serves as a versatile tool that can be reused across various C projects, eliminating the need for relying on external dependencies or standard library functions in certain contexts.

---

### 🌟 **Why Libft?**

Libft is not just about creating a library; it’s about gaining confidence in **low-level programming** and **memory management**. It’s a project that pushes you to write cleaner, more efficient code that can be applied across a variety of **C programming** scenarios.


<p align="center">
  <a href="#libft">Beginning ⬆️ ⬆️</a> • 
  <a href="#structure">Structure ➡️</a>
</p>

## 🧬 **Structure: Inside Libft** <a id="structure"></a>

The **mandatory part** of this project focuses on reimplementing several core functions from the standard C library.
Libft is organized into a series of essential **function categories**, each based on their specific purpose and functionality, that replicate or extend standard C library functionalities. 
This structure ensures modularity, clarity, and efficiency, making it easier to implement and maintain in future projects.
The primary categories include **Libc** functions and **Additional functions**.

### 🔹 **Core Categories**

1. **Libc Functions**

   These are the **reimplementations of the standard C library functions**, which are fundamental for many C programs. The goal is to manually recreate these commonly used functions to gain a deeper understanding of their inner workings and behavior.
   Therefore, by rebuilding these, developers gain insight into their low-level operations and behavior, from **memory management** to **string manipulation**.

2. **Additional Functions**

   Complementing the standard library, these utility functions add extra capabilities to extend Libft’s functionality. 
   While not part of the standard C library, they provide helpful features that enhance the library's versatility.

---

### 📂 **Function Groups**

Within these two main categories, each function is organized into more specific group based on the **type of operation** they perform.
These groups include:

- **🧵 String Functions:** Handle various string operations like length calculation, copying, concatenation, and comparison.
- **💾 Memory Functions:** Perform essential memory operations, including memory allocation, memory setting, copying, and freeing.
- **🔧 Utility Functions:** Provide a range of practical useful operations, such as type conversions, mathematical computations and handling character-specific manipulations.
- **🔗 Linked List Functions:** A suite of functions dedicated to linked list manipulation, including creating, traversing, and modifying list nodes, allowing for dynamic data structures within C.

---

> 💡 **Organizational Insight:**  
>
> By categorizing the functions into these groups, Libft ensures that each function is reimplemented with a specific purpose, achieving a high level of **modularity**, **clarity** and easy to use in future projects, promoting reusability and efficiency.

---

The **Libft Structure** balances **functionality** with **elegance**, ensuring that every component is purposeful and easy to integrate across diverse C projects.


## 🌳 **Directory Tree**

<pre>
Libft
|
├── 📂 <span style="color:#6A5ACD">list</span>
|   |
│   ├── 📄 ft_lstadd_back
│   ├── 📄 ft_lstadd_front
│   ├── 📄 ft_lstclear
│   ├── 📄 ft_lstdelone
│   ├── 📄 ft_lstiter
│   ├── 📄 ft_lstlast
│   ├── 📄 ft_lstmap
│   ├── 📄 ft_lstnew
│   └── 📄 ft_lstsize
|
├── 📂 <span style="color:#6A5ACD">memory</span>
|   |
│   ├── 📄 ft_bzero
│   ├── 📄 ft_calloc
│   ├── 📄 ft_memchr
│   ├── 📄 ft_memcmp
│   ├── 📄 ft_memcpy
│   ├── 📄 ft_memmove
│   └── 📄 ft_memset
|
├── 📂 <span style="color:#6A5ACD">strings</span>
|   |
│   ├── 📄 ft_split
│   ├── 📄 ft_strchr
│   ├── 📄 ft_strdup
│   ├── 📄 ft_striteri
│   ├── 📄 ft_strjoin
│   ├── 📄 ft_strlcat
│   ├── 📄 ft_strlcpy
│   ├── 📄 ft_strlen
│   ├── 📄 ft_strmapi
│   ├── 📄 ft_strncmp
│   ├── 📄 ft_strnstr
│   ├── 📄 ft_strrchr
│   ├── 📄 ft_strtrim
│   └── 📄 ft_substr
|
└── 📂 <span style="color:#6A5ACD">utils</span>
    |
    ├── 📄 ft_atoi
    ├── 📄 ft_isalnum
    ├── 📄 ft_isalpha
    ├── 📄 ft_isascii
    ├── 📄 ft_isdigit
    ├── 📄 ft_isprint
    ├── 📄 ft_itoa
    ├── 📄 ft_putchar_fd
    ├── 📄 ft_putendl_fd
    ├── 📄 ft_putnbr_fd
    ├── 📄 ft_putstr_fd
    ├── 📄 ft_tolower
    └── 📄 ft_toupper
</pre>

> **Additional Directories**  
> - **📁 `/includes`**: Contains the project header file.
> - **📁 `/srcs`**: Holds the main source code files for the project.
> - **📁 `/bonus`**: Contains any bonus features and extra functions for the project.

<p align="center">
  <a href="#intro">⬅️ Introduction</a> • 
  <a href="#libft">Beginning ⬆️ ⬆️</a> • 
  <a href="#functions">Functions ➡️</a>
</p>


## Functions <a id="functions"></a>

<h3>
  <p align="center"> 
    <a href="#string">🧵 String</a> • 
    <a href="#memory">💾 Memory</a> • 
    <a href="#utility">🔧 Utility</a> • 
    <a href="#lists">🔗 Lists (Bonus)</a> • 
  </p>
</h3>

### 🧵 **String Functions** <a id="string"></a>

The **String functions** category encompasses a variety of operations essential for handling and manipulating strings in C. These functions focus on tasks such as calculating string length, copying, concatenating, and searching for specific characters or substrings within a string.

#### ✨ **Reimplemented C Standard Library Functions**

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_strlen**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strlen) | Computes the length of a string, excluding the null-terminating character. |
| [**ft_strlcpy**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strlcpy) | Copies a specified number of characters from one string to another, ensuring the destination string is null-terminated. |
| [**ft_strlcat**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strlcat) | Appends a specified number of characters from one string to another, ensuring null-termination. |
| [**ft_strchr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strchr) | Searches for the first occurrence of a given character in a string. |
| [**ft_strrchr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strrchr) | Searches for the last occurrence of a given character in a string. |
| [**ft_strncmp**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strncmp) | Compares a specified number of characters between two strings to check for equality. |
| [**ft_strnstr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strnstr) | Searches for the first occurrence of a substring within a string, up to a specified length. |
| [**ft_strdup**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strdup) | Creates a new string that is a duplicate of an existing string. |

#### 🔧 **Additional String Functions**

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_substr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_substr) | Creates a new substring from a given string, starting at a specified position and of a specified length. |
| [**ft_strjoin**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strjoin) | Joins two strings together into a new string. |
| [**ft_strtrim**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strtrim) | Removes specified characters from the beginning and end of a string. |
| [**ft_split**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_split) | Splits a string into an array of substrings based on a specified delimiter. |
| [**ft_strmapi**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strmapi) | Applies a function to each character in a string, returning a new string with the results of the function applied. |
| [**ft_striteri**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_striteri) | Similar to `ft_strmapi`, but the function receives both the index and the character, allowing for more complex operations. |

These functions provide a comprehensive toolkit for string manipulation, ensuring tasks such as substring extraction, joining, trimming, and splitting can be performed with ease and flexibility.


<p align="center">
  <a href="#structure">⬅️ Structure</a> • 
  <a href="#functions">Functions ⬆️</a> • 
  <a href="#libft">Beginning ⬆️ ⬆️</a> • 
  <a href="#memory">Memory ➡️</a>
</p>

### 🧠 **Memory Functions** <a id="memory"></a>

The **Memory functions** category focuses on operations that manipulate raw memory blocks, performing tasks such as setting values, copying, comparing, and allocating memory. These functions are essential for low-level memory management, a crucial aspect of systems programming in C.

#### ✨ **Reimplemented C Standard Library Functions**

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_memset**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memset) | Fills a specified number of bytes in a memory block with a given value. |
| [**ft_bzero**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_bzero) | Sets all bytes in a memory block to zero, effectively clearing the memory. |
| [**ft_memcpy**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memcpy) | Copies a specified number of bytes from one memory block to another. |
| [**ft_memmove**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memmove) | Similar to `ft_memcpy`, but handles overlapping memory areas by ensuring the source is safely moved to the destination. |
| [**ft_memchr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memchr) | Searches for the first occurrence of a specified byte in a memory block. |
| [**ft_memcmp**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memcmp) | Compares two memory blocks byte-by-byte, up to a specified number of bytes, to determine their equality. |
| [**ft_calloc**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_calloc) | Allocates memory for an array of a specified number of elements, initializing the memory to zero. |

These functions are designed to operate on raw memory, performing tasks where the content or structure of the memory is not as important as the manipulation of the underlying bytes. They enable efficient memory management, which is vital for tasks like buffer handling and memory clearing.

Together, these memory functions cover common memory manipulation tasks while ensuring safety and efficiency, particularly when dealing with raw memory operations, allocation, and initialization.

<p align="center">
  <a href="#string">⬅️ String</a> • 
  <a href="#functions">Functions ⬆️</a> • 
  <a href="#libft">Beginning ⬆️ ⬆️</a> • 
  <a href="#utility">Utility ➡️</a>
</p>

### 🔧 **Utility Functions** <a id="utility"></a>

The **Utility functions** category encompasses a variety of functions that perform operations on characters, strings, and data conversions. These functions are essential for handling common tasks related to character classification, manipulation, and input/output operations.

#### ✨ **Character Classification and Conversion**

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_toupper**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_toupper) | Converts a character to uppercase based on its ASCII value. |
| [**ft_tolower**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_tolower) | Converts a character to lowercase based on its ASCII value. |
| [**ft_atoi**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_atoi) | Converts a string representation of an integer to an actual integer. |
| [**ft_isalpha**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isalpha) | Checks if a character is alphabetic. |
| [**ft_isdigit**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isdigit) | Checks if a character is a digit. |
| [**ft_isalnum**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isalnum) | Checks if a character is alphanumeric (either a letter or a digit). |
| [**ft_isascii**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isascii) | Checks if a character is within the ASCII range. |
| [**ft_isprint**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isprint) | Checks if a character is printable (i.e., not a control character). |
| [**ft_itoa**](URL_DA_FUNCAO) | Converts an integer to a string representation. |

#### ✨ **File Descriptor Output Functions**

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_putchar_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putchar_fd) | Writes a single character to the specified file descriptor. |
| [**ft_putstr_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putstr_fd) | Writes a string to the specified file descriptor. |
| [**ft_putendl_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putendl_fd) | Writes a string followed by a newline to the specified file descriptor. |
| [**ft_putnbr_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putnbr_fd) | Writes an integer (converted to a string) to the specified file descriptor. |

These utility functions provide a comprehensive toolkit for handling characters and strings, offering crucial operations for parsing and manipulating textual input, as well as writing data to different output streams like standard output or files.

<p align="center">
  <a href="#memory">⬅️ Memory</a> • 
  <a href="#functions">Functions ⬆️</a> • 
  <a href="#functions">Beginning ⬆️ ⬆️</a> • 
  <a href="#lists">Lists ➡️</a>
</p>

### 📋 **List Functions (Bonus)** <a id="lists"></a>

The **List functions** are focused on operations involving linked lists, a fundamental and flexible data structure often used in C programming for dynamic memory management and efficient insertion/deletion of elements. These functions provide the necessary tools to create, manipulate, and traverse these structures.

#### 🔗 **Linked List Operations**

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_lstnew**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstnew) | Creates a new node for the linked list and returns a pointer to it. |
| [**ft_lstadd_front**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstadd_front) | Adds a new node at the beginning of the list, modifying the head. |
| [**ft_lstsize**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstsize) | Returns the number of nodes in the list. |
| [**ft_lstlast**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstlast) | Returns the last node in the list. |
| [**ft_lstadd_back**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstadd_back) | Adds a new node to the end of the list. |
| [**ft_lstdelone**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstdelone) | Deletes a single node from the list, freeing its memory. |
| [**ft_lstclear**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstclear) | Clears the entire list by deleting all nodes. |
| [**ft_lstiter**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstiter) | Iterates through the list and applies a given function to each element. |
| [**ft_lstmap**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/list/ft_lstmap) | Iterates through the list, applies a function to each element, and returns a new list with the modified values. |

Linked lists are widely used in various data structures, algorithms, and system-level programming tasks due to their flexibility in terms of dynamic memory allocation and efficient insertion/removal operations. By using these functions, developers can easily work with lists to store and process data in a structured, efficient way.

<p align="center">
  <a href="#utility">⬅️ Utility</a> • 
  <a href="#functions">Functions ⬆️</a> • 
  <a href="#functions">Beginning ⬆️ ⬆️</a> • 
  <a href="#Compilation">Compilation ➡️</a>
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
