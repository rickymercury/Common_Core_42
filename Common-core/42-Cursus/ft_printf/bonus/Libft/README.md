![](https://github.com/jotavare/jotavare/blob/main/42/banners/piscine_and_common_core/github_piscine_and_common_core_banner_libft.png)

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Topics  <a id="libft"></a>
</h3>

---

<h3 align="center" style="font-weight: bold; font-size: 1.2em; line-height: 1.5em; color: #333;">
  <p>
    <a href="#intro" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🗣️ Introduction</a> • 
    <a href="#structure" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🧬 Structure</a> • 
    <a href="#functions" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">📂 Functions</a> • 
    <a href="https://github.com/rickymercury/Common_Core_42/blob/main/Common-core/42-Cursus/Libft/srcs/subjects/libft.en.subject.pdf" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">📌 Subject</a> • 
    <a href="#compilation" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Compilation</a>
  </p>
</h3>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🗣️ Introduction: Project Overview <a id="intro"></a>
</h3> 

This repository hosts a custom C library known as **<span style="color:blue">Libft</span>**, which is implemented as part of a coding project. 
The primary objective of this project is to develop a **static library** (`.a`) by reimplementing a variety of standard C library functions, as well as adding a few additional, useful functions that enhance the functionality of the C programming language.

The **libft** project at 42 is one of the first challenges that we face, designed to deepen our understanding of the C programming language by implementing a variety of standard library functions from scratch. 
The project’s core goal is to help us gain insight into how essential functions like memory management, string manipulation, and other basic operations are actually implemented under the hood, beyond what’s provided by the built-in C standard library.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    What is a Static Library?
</h3> 

>
> A **static library** is essentially a collection of precompiled **object files** (`.o`) bundled together. 
These object files are linked directly into the final executable during the compilation process, meaning the functions from the static library become part of the executable itself. 
This process contrasts with **dynamic libraries**, which are linked at runtime.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🎯 Main Goals
</h3> 

>
>The main goal of this project is:

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Understanding Standard Library Functions
</h3> 

 >The project provides a deeper, hands-on understanding of how standard functions are implemented. 
 Instead of using pre-built functions, we manually code them, which allows us to appreciate the complexities behind even simple operations like string comparison or memory copying. 
 This helps to develop a stronger foundational knowledge of C, focusing on critical aspects like memory management, pointer arithmetic, and low-level operations.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Creating a Reusable Tool for C Projects
</h3>
   
>One of the key benefits of the **libft** project is that it enables us to build a reusable library of functions that can be used in all future C projects at 42. 
This custom library serves as a versatile tool, helping students avoid the need for external dependencies or reliance on the standard library in specific contexts. 
It equips us with a personalized set of building blocks for our C programming journey.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Importance for Future Projects
</h3> 

>
>The **libft** project serves as a foundational step that impacts many of the future projects that we'll encounter at 42. 
The functions coded in this library will be directly used and expanded upon in later assignments/subjects, making it essential for us to master the underlying concepts and ensure the library is both robust and efficient. 
>
>By the end of this project, we won´t only have a deeper understanding of how core C functions work but also possess a valuable tool that enhances their programming efficiency and autonomy in future assignments.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🌟 Why Libft?
</h3> 

>
>Libft is not just about creating a library; it’s about gaining knowledge in **low-level programming** and **memory management**. 
It’s a project that pushes us to write cleaner, more efficient code that can be applied across a variety of **C programming** scenarios.



---

<h3 align="center">
    🧬 Structure: Inside Libft <a id="structure"></a> 
</h3>

---

<h2 align="center" style="font-weight: bold; font-size: 1.2em; line-height: 1.5em; color: #333;">
  <p>
    <a href="#intro" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🗣️ Introduction</a> • 
    <a href="#libft" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">⬆️ ⬆️ Top</a> • 
    <a href="#functions" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">📂 Functions</a> • 
    <a href="#compilation" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Compilation</a>
  </p>
</h2>

---

The **mandatory part** of this project focuses on reimplementing several core functions from the standard C library.

**Libft** is structured into a series of essential **function categories**, each designed around on a specific purpose or functionality. 

This structure ensures modularity, clarity, and efficiency, making it easier to implement and maintain in future projects.

The primary categories include **Libc** functions and **Additional functions**.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Libc Functions
</h3> 

>
> These are the **reimplementations of the standard C library functions**, which are fundamental for many C programs. 
  The goal here is to manually rebuild essential commonly used functions to gain a deeper understanding of their inner workings and behavior.
>
> By doing so, developers not only understand how these functions work but also develop essential skills in **memory management**, **string manipulation**, and core system operations.
> Reimplementing these functions reinforces the foundational knowledge of C programming.
>
<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Additional Functions
</h3> 

>
>  Complementing the standard library, these utility functions **extend** the functionality of Libft beyond the standard C library.
   While not part of C's standard library, these functions provide useful tools and features that enhance the usabiity and versality of the library.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    📂 Function Groups
</h3> 

>
>Within these two main categories, each function is organized into specific group based on the **type of operation** they perform.
This ensures that each group serves a particular purpose, facilitating easy navigation and future expansion.
>
>These groups include:
>
>- **🧵 String Functions:** A collection of functions that handle various string operations, such as calculating string length, copying, concatenation, and comparison.
>
>- **💾 Memory Functions:** Functions dedicated to performing essential memory operations, such as memory allocation, setting, copying, and freeing memory.  
>
>- **🔧 Utility Functions:** This group provides a wide range of practical operations, including type conversions, mathematical computations, and character-specific manipulations. These functions are often used across different parts of a program to improve performance or handle specific use cases.
>
>- **🔗 Linked List Functions:** A specialized suite of functions dedicated to handling dynamic data structures like linked lists. These functions include the ability to create, traverse, and manipulate linked list nodes, which are commonly used in complex C projects.  

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    💡 Organizational Insight:
</h3> 

>
> By categorizing the functions in **Libft** into these groups, the project ensures that each function serves a **specific purpose**. This structure promotes **modularity**, **clarity**, and **efficiency**, making the library easier to maintain and extend. 
>
>Moreover, this organizational approach supports **reusability** across multiple projects, fostering cleaner and more consistent code.

---

In conclusion, the **Libft Structure** elegantly balances **functionality** with **organization**, ensuring that every function has a clear and purposeful role. 

This organization not only enhances the usability of the library but also makes it a robust tool for future C programming assignments, contributing to cleaner, more efficient, and modular code.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🌳 Directory Tree
</h3>


<pre>
Libft
|
├── 📂 <span style="color:#6A5ACD">list</span>         
|   |
│   ├── 📄 ft_lstadd_back    # Adds a new element at the end of the list.
│   ├── 📄 ft_lstadd_front   # Adds a new element at the beginning of the list.
│   ├── 📄 ft_lstclear       # Clears the entire list.
│   ├── 📄 ft_lstdelone      # Deletes a single element of the list.
│   ├── 📄 ft_lstiter        # Iterates through a list and applies a function to each element.
│   ├── 📄 ft_lstlast        # Returns the last element of the list.
│   ├── 📄 ft_lstmap         # Applies a function to each element and returns a new list.
│   ├── 📄 ft_lstnew         # Creates a new list element.
│   └── 📄 ft_lstsize        # Returns the size of the list.
|
├── 📂 <span style="color:#6A5ACD">memory</span>     
|   |
│   ├── 📄 ft_bzero          # Sets a block of memory to zero.
│   ├── 📄 ft_calloc         # Allocates memory and sets it to zero.
│   ├── 📄 ft_memchr         # Searches a block of memory for a specific character.
│   ├── 📄 ft_memcmp         # Compares two blocks of memory.
│   ├── 📄 ft_memcpy         # Copies a block of memory to another location.
│   ├── 📄 ft_memmove        # Moves a block of memory to another location.
│   └── 📄 ft_memset         # Sets a block of memory to a specified value.
|
├── 📂 <span style="color:#6A5ACD">strings</span>     
|   |
│   ├── 📄 ft_split          # Splits a string into an array of substrings.
│   ├── 📄 ft_strchr         # Searches a string for a specific character.
│   ├── 📄 ft_strdup         # Duplicates a string.
│   ├── 📄 ft_striteri       # Applies a function to each character of a string.
│   ├── 📄 ft_strjoin        # Joins two strings into one.
│   ├── 📄 ft_strlcat        # Appends one string to another with a size limit.
│   ├── 📄 ft_strlcpy        # Copies a string with a size limit.
│   ├── 📄 ft_strlen         # Returns the length of a string.
│   ├── 📄 ft_strmapi        # Applies a function to each character of a string and returns a new string.
│   ├── 📄 ft_strncmp        # Compares the first n characters of two strings.
│   ├── 📄 ft_strnstr        # Locates a substring within a string, with a size limit.
│   ├── 📄 ft_strrchr        # Searches a string for the last occurrence of a character.
│   ├── 📄 ft_strtrim        # Trims a string by removing specific characters from both ends.
│   └── 📄 ft_substr         # Extracts a substring from a string.
|
└── 📂 <span style="color:#6A5ACD">utils</span>    
    |
    ├── 📄 ft_atoi           # Converts a string to an integer.
    ├── 📄 ft_isalnum        # Checks if a character is alphanumeric.
    ├── 📄 ft_isalpha        # Checks if a character is alphabetic.
    ├── 📄 ft_isascii        # Checks if a character is ASCII.
    ├── 📄 ft_isdigit        # Checks if a character is a digit.
    ├── 📄 ft_isprint        # Checks if a character is printable.
    ├── 📄 ft_itoa           # Converts an integer to a string.
    ├── 📄 ft_putchar_fd     # Writes a character to a file descriptor.
    ├── 📄 ft_putendl_fd     # Writes a string followed by a newline to a file descriptor.
    ├── 📄 ft_putnbr_fd      # Writes an integer to a file descriptor.
    ├── 📄 ft_putstr_fd      # Writes a string to a file descriptor.
    ├── 📄 ft_tolower        # Converts a character to lowercase.
    └── 📄 ft_toupper        # Converts a character to uppercase.
</pre>


> **Additional Directories**  
> - **📁 `/includes`**: Contains the project header file.
> - **📁 `/srcs`**: Holds the main source code files for the project.
> - **📁 `/bonus`**: Contains any bonus features and extra functions for the project.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    📂 Functions <a id="functions"></a>
</h3>

---

<h3>
  <p align="center"> 
    <a href="#string">🧵 String</a> • 
    <a href="#memory">💾 Memory</a> • 
    <a href="#utility">🔧 Utility</a> • 
    <a href="#lists">🔗 Lists (Bonus)</a> 
  </p>
</h3>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🧵 String Functions <a id="string"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#structure">⬅️ Structure</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#libft">⬆️ ⬆️ Top</a> • 
  <a href="#memory">Memory ➡️</a>
</p>
</h3>

---

The **String functions** category in **Libft** provides a comprehensive set of operations essential for handling and manipulating strings in C.

These functions provide a rich toolkit for string manipulation, enabling operations such as calculating string length, substring extraction, string concatenation, trimming, and splitting. 

Whether it's for handling user input, processing data, or implementing complex algorithms, **Libft's String Functions** offer the flexibility and efficiency necessary to perform these tasks seamlessly.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    ✨ **Reimplemented C Standard Library Functions
</h3>

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_strlen**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strlen) | Finds the length of a string, excluding the null-terminating character. |
| [**ft_strlcpy**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strlcpy) | Copies a specified number of characters from one string to another, ensuring the destination string is null-terminated. |
| [**ft_strlcat**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strlcat) | Appends a specified number of characters from one string to another, ensuring null-termination. |
| [**ft_strchr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strchr) | Searches for the first occurrence of a given character in a string. |
| [**ft_strrchr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strrchr) | Searches for the last occurrence of a given character in a string. |
| [**ft_strncmp**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strncmp) | Compares a specified number of characters between two strings to check for equality. |
| [**ft_strnstr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strnstr) | Searches for the first occurrence of a substring within a string, up to a specified length. |
| [**ft_strdup**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strdup) | Creates a new string that is a duplicate of an existing string. |

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🔧 Additional String Functions
</h3>

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_substr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_substr) | Creates a new substring from a given string, starting at a specified position and of a specified length. |
| [**ft_strjoin**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strjoin) | Joins two strings together into a new string. |
| [**ft_strtrim**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strtrim) | Removes specified characters from the beginning and end of a string. |
| [**ft_split**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_split) | Splits a string into an array of substrings based on a specified delimiter. |
| [**ft_strmapi**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_strmapi) | Applies a function to each character in a string, returning a new string with the results of the function applied. |
| [**ft_striteri**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/strings/ft_striteri) | Similar to `ft_strmapi`, but the function receives both the index and the character, allowing for more complex operations. |

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    💾 Memory Functions <a id="memory"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#string">⬅️ String</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#libft">⬆️ ⬆️ Top</a> • 
  <a href="#utility">Utility ➡️</a>
</p>
</h3>

---

The **Memory functions** section of **Libft** focuses on operations essential for low-level memory management, an integral part of systems programming in C.
These functions enable manipulation of raw memory blocks, covering tasks such as setting values, copying, comparing, and allocating memory. 
Through these functions, we gain deeper insight int how memory is handled in C, which is crucial for building efficient, error-free programs.

These are foundational tools for managing memory safely and efficiently in C. By implementing them from scratch, you gain a solid understanding of memory operations, allowing for more robust and optimized code when handling raw data.

---
<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    ✨ Reimplemented C Standard Library Functions
</h3>

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_memset**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memset) | Fills a specified number of bytes in a memory block with a given value, often used to initialize or reset memory. |
| [**ft_bzero**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_bzero) | Sets all bytes in a memory block to zero, effectively clearing the memory. |
| [**ft_memcpy**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memcpy) | Copies a specified number of bytes from one memory block to another. |
| [**ft_memmove**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memmove) | Similar to `ft_memcpy`, but designed to safely handle overlapping memory areas by ensuring the source is safely moved to the destination. |
| [**ft_memchr**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memchr) | Searches for the first occurrence of a specified byte in a memory block. |
| [**ft_memcmp**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_memcmp) | Compares two memory blocks byte-by-byte, up to a specified number of bytes, to determine their equality. |
| [**ft_calloc**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/memory/ft_calloc) | Allocates memory for an array of a specified number of elements, initializing the memory to zero for safer, pre-initialized use. |

---


<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🔧 Utility Functions <a id="utility"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#memory">⬅️ Memory</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#functions">⬆️ ⬆️ Top</a> • 
  <a href="#lists">Lists ➡️</a>
</p>
</h3>

---

The **Utility functions** category in **Libft** includes versatile functions that are essential for handling common tasks related to text processing, I/O handling, and data handling, covering essential tasks like text case conversion, character checking, and formatted output, enhancing efficiency in programming tasks.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    ✨ Character Classification and Conversion
</h3>

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_toupper**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_toupper) | Converts a character to uppercase based on its ASCII value, useful for case manipulation in string handling. |
| [**ft_tolower**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_tolower) | Converts a character to lowercase based on its ASCII value. |
| [**ft_atoi**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_atoi) | Converts a string representing an integer to an actual integer value, aiding in data parsing. |
| [**ft_isalpha**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isalpha) | Checks if a character is alphabetic (a-z, A-Z). |
| [**ft_isdigit**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isdigit) | Checks if a character is a digit (0-9), essential for numerical validation. |
| [**ft_isalnum**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isalnum) | Checks if a character is alphanumeric (either a letter or a digit). |
| [**ft_isascii**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isascii) | Checks if a character falls within the ASCII range, useful for data validation. |
| [**ft_isprint**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_isprint) | Checks if a character is printable (i.e., not a control character). |
| [**ft_itoa**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_itoa) | Converts an integer to its string representation, useful for converting numerical data to text format. |

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    ✨ File Descriptor Output Functions
</h3>

| **Function** | **Description** |
|--------------|-----------------|
| [**ft_putchar_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putchar_fd) | Writes a single character to a specified file descriptor, facilitating low-level output control. |
| [**ft_putstr_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putstr_fd) | Writes a string to a specified file descriptor, allowing for versatile string output handling. |
| [**ft_putendl_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putendl_fd) | Writes a string followed by a newline to a specified file descriptor, useful for structured output with line breaks. |
| [**ft_putnbr_fd**](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/Libft/srcs/Study/utils/ft_putnbr_fd) | Writes an integer (converted to a string) to a specified file descriptor, enabling flexible numeric output. |

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    📋 List Functions (Bonus) <a id="lists"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#utility">⬅️ Utility</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#libft">⬆️ ⬆️ Top</a> • 
  <a href="#compilation">Compilation ➡️</a>
</p>
</h3>

---

The **List functions** are focused on operations involving linked lists, a fundamental and flexible data structure often used in C programming for dynamic memory management and efficient insertion/deletion of elements. These functions provide the necessary tools to create, manipulate, and traverse these structures.

Linked lists are widely used in various data structures, algorithms, and system-level programming tasks due to their flexibility in terms of dynamic memory allocation and efficient insertion/removal operations. By using these functions, developers can easily work with lists to store and process data in a structured, efficient way.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🔗 Linked List Operations
</h3>

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

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🕹️ Compilation and Usage <a id="compilation"></a>
</h3>

---

<h1>
<p align="center">
  <a href="#lists">⬅️ Lists</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#libft">⬆️ ⬆️ Top</a> • 
</p>
</h1>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Makefile
</h3>

A `Makefile` is provided to automate the compilation process. The Makefile includes the following rules:

- `all`: Compiles the library (`libft.a`).
- `clean`: Removes object files.
- `fclean`: Removes object files and the library (`libft.a`).
- `re`: Recompiles the entire project.
- `bonus`: Compiles the bonus part of the project.

>To compile the library, simply run:
>```bash
>make
>```
>This will generate the `libft.a` library, which can be linked in other projects to use all functions.
>
><!--
>To compile the bonus part, use:
>```bash
>make bonus
>```
>
>To compile the bonus part and test, use:
>```bash
>make test
>```
-->

<pre>
# **************************************************************************** #
#                                 VARIÁVEIS                                    #
# **************************************************************************** #

# Nome da biblioteca
NAME = libft.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Pastas
SRC_DIR = srcs
BONUS_DIR = bonus
OBJ_DIR = obj
INC_DIR = includes

# Arquivos SRCS e bônus
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
       ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
       ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
       ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c 

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c \
             ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
             ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Cria os arquivos objetos principais e de bônus
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

RM = rm -f
COMPRESS = ar rcs

# **************************************************************************** #
#                                COMPILAÇÃO                                    #
# **************************************************************************** #

# Regra all: Compila os arquivos principais e cria a biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

# Regra para compilar arquivos .o a partir dos arquivos .c e criar a pasta
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Regra para compilar arquivos bônus a partir da pasta bônus
$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled bonus: $<"

# Regra para compilar a biblioteca incluindo os bônus
bonus: $(NAME) $(OBJS_BONUS)
	@$(COMPRESS) $(NAME) $(OBJS_BONUS)
	@echo "Bonus added to $(NAME)!"

# Regra clean: Remove os arquivos objetos (.o)
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Cleaned up object files."

# Regra fclean: Remove os arquivos objetos (.o) e a biblioteca (libft.a)
fclean: clean
	@$(RM) $(NAME)
	@echo "All cleaned up: $(NAME)!"

# Regra re: Limpa tudo e recompila
re: fclean all

.PHONY: all clean fclean re bonus
<pre>


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
