![](https://github.com/jotavare/jotavare/blob/main/42/banners/piscine_and_common_core/github_piscine_and_common_core_banner_ft_printf.png
)
<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Topics  <a id="ft_printf"></a>
</h3>

---

<h3 align="center" style="font-weight: bold; font-size: 1.2em; line-height: 1.5em; color: #333;">
  <p>
    <a href="#intro" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🗣️ Introduction</a> • 
    <a href="#structure" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🧬 Structure</a> • 
    <a href="#functions" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">📂 Functions</a> • 
    <a href="https://github.com/rickymercury/Common_Core_42/blob/main/Common-core/42-Cursus/ft_printf/srcs/Subjects/ft_printf.pdf" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">📌 Subject</a> • 
    <a href="#compilation" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Compilation</a>
  </p>
</h3>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🗣️ Introduction: Project Overview <a id="intro"></a>
</h3> 

This repository features a custom implementation of the **printf** function, crafted as part of the 42 shcool coding curriculum.

This project serves as a stepping stone, offering deeper insights into how fundamental C library functions operate in its iternal workings.

The project replicates the functionality of the standard C library's **printf**, providing a versatile tool for formatted output in projects where library functions may not be available.

The ft_printf challenge reinforces essential C programming concepts and cultivates foundational skills in low-level coding and memory management.

>The main goal of the `ft_printf` project is to implement a custom version of the standard `printf` function, offering essential functionality for formatted output while reinforcing foundational skills in C programming and low-level memory management.

>The **ft_printf** focuses on re-creating core behaviors of **printf** from scratch, demanding an in-depth understanding of key programming concepts.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🔧 Create a Reusable Tool for Future Projects
</h3> 

>Since certain 42 School projects restrict the use of standard C library functions, making it necessary to create custom versions of commonly used functions, the`ft_printf` offers a custom alternative that can be adapted across various projects:
>
>  - **Eliminate Standard Library Dependencies**: Substitute functions like `malloc`, `write`, and `free` with custom, internally managed implementations if required by project guidelines.
>  - **Optimized for Compatibility**: `ft_printf` is intended to be reusable, providing formatted output capabilities without relying on standard library functions such as `printf`, `itoa`, or `strlen`.
>  - **Flexible Integration**: The custom `ft_printf` can be adapted to different 42 project requirements, enabling formatted output functionality in scenarios where only a subset of standard library functions is permitted.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🚀 Why `ft_printf` Matters
</h3> 

The `ft_printf` project pushes us beyond basic library usage towards a more autonomous approach to programmig.

By tackling this challenge we gain pratical insights into the internal workings of printf, addressing complex requirements with efficient memory handling and precision in code execution, all of which are essential for advancing in systems programming and software development.

Completing `ft_printf` prepares us for increasingly complex projects, instilling confidence in their ability to write optimized, foundational code that mimics critical standard library functions. 

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🧬 Structure: Inside ft_printf <a id="structure"></a>
</h3> 

---

<h2 align="center" style="font-weight: bold; font-size: 1.2em; line-height: 1.5em; color: #333;">
  <p>
    <a href="#intro" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">🗣️ Introduction</a> • 
    <a href="#ft_printf" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">⬆️ ⬆️ Top</a> • 
    <a href="#functions" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">📂 Functions</a> • 
    <a href="#compilation" style="color: #2b7a78; text-decoration: none; margin: 0 10px;">Compilation</a>
  </p>
</h2>

---

The ft_printf project is structured around a central function, ft_printf, which processes various data types and applies formatting options for strings, intergers, characters, and hexadecimal values.

This implementation closely mirrors the standard **printf** function making it versatile and adaptable for projects requiring formatted output without external libraries.

The main function interacts with a suite of specialized helpter functions, each dedicated to processing and formatting a specific data type according to the given format specifiers.

This modular approach allows ft_printf to interpret and format different types of input consistently, and each auxiliary function has a clear, focused role within the formatting pipeline. 

Together, these components form a comprehensive and reusable implementation that offers essential functionality of the standard printf while maintaining independence from the standard library.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Key Concepts
</h3> 

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🧩 String Parsing and Handling
</h3> 

> A core responsability of `ft_printf` is the ability to scan through a string, interpret format specifiers, and process each component accordingly. 
>
> In other words, a core responsibility of `ft_printf` is to parse input strings for format specifiers, process them, and format output accordingly. This requires a approach to scanning, interpreting, and handling memory.
>
> This involves:
>
>  - **String Traversal**: ft_printf scans each character in the string to identify `%` symbols which indicate the start of a format specifier.
>
>  - **Specifier Parsing**: Recognizes and interpreting various format specifiers (such as `%d`, `%s`, `%x`), flags (e.g., `+`, `-`, `0`), width, precision, and length modifiers, applying each setting precisely to achieve the correct output format.
>
>  - **Efficient Memory Management**: Manages memory dynamically by allocating and deallocating temporary buffers, preventing leaks and avoiding overflows. This is crucial for processing large or complex strings without compromising system stability.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🛠️ Type Conversion and Output Formatting
</h3> 

> Handling various data types (such as integers, characters, and strings) and formatting them accurately (e.g., `%d`, `%s`, `%x`) to display values in specific formats, as `printf`, does requires an extensive suite of conversion and formatting functions. 

> Each data type has unique requirements that `ft_printf` accomodates through custom implementations. 
>
>  - **Data Type Handling**: Managing integers, characters, pointers, and strings, each with specialized formatting requirements and conversion rules. 
>
>  - **Format Specifiers**: Implements a range of format specifiers allowing `ft_printf` to format values as:
>
>    - `%d` and `%i` for signed integers
>    - `%u` for unsigned integers
>    - `%x` and `%X` for hexadecimal numbers
>    - `%c` for characters
>    - `%s` for strings
>    - `%p` for pointers
>
>  - **Flags, Width, and Precision**: Handles additional flags (e.g., `-` for left-justification, `0` for zero-padding), controls minimum number of characters width settings, and applies precision settings for number of digits or characters displayed.
>
>  - **Custom Conversion Functions**: Creating helper functions to convert data types into strings, adds padding, and applies the specified flags to produce the correct output format.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🧪 Error Handling and Edge Cases
</h3> 

> To ensure robust functionatily, `ft_printf` adresses common edge cases, making it resilient against invalid input and atypical usage scenarios.
>
>  - **Null Pointers**: Safely handles NULL pointers by displaying `(null)` for `NULL` strings and ensuring pointers do not cause segmentation faults.

>  - **Precision and Width Edge Cases**: Manages minimum width and precision requirements, aligning output and handling zero-width or zero-precision cases.

>  - **Specifier Validation**: Validates and skips unsupported format specifiers, avoiding undefined behavior and maintaing control over output.

>  - **Recursive or Iterative Formatting**: Ensuring output for recursive format calls remains efficient and controlled to avoid buffer overflows or infinite loops.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🌳 Directory Tree 
</h3> 

<pre>
📂 ft_printf
├── 📂includes/           # Directory containing header files.
│   ├── 📄 ft_printf.h    # Header file with function prototypes and type definitions.
│   └── 📄 libft.h        # Additional header with common utility functions.
├── 📂 Libft              # External library for basic functions (custom implementations).
├── 📄 Makefile           # Build automation file for compiling the project.
└── 📂 srcs/              # Directory containing the project's source code files.
    ├── 📄 ft_print_c.c   # Processes and formats characters.
    ├── 📄 ft_print_d.c   # Processes and formats signed integers.
    ├── 📄 ft_printf.c    # Core function handling main format logic.
    ├── 📄 ft_print_p.c   # Processes and formats pointer addresses.
    ├── 📄 ft_print_s.c   # Processes and formats strings.
    ├── 📄 ft_print_u.c   # Processes and formats unsigned integers.
    └── 📄 ft_print_x.c   # Processes and formats hexadecimal values.
</pre>

> - **`/includes`**: Contains header files, including `ft_printf.h`, which provides function prototypes and data structure definitions used throughout the project. 
> - **`/srcs`**: Contains source code files, each focusing on specific functionalities, such as formatting different data types (`ft_print_d.c`, `ft_print_x.c`).

---

## Groups

|**General**|**Print**|
|:---------:|:-------:|
|`ft_printf`| `ft_print_c`, `ft_print_d`, `ft_print_u`, `ft_print_p`, `ft_print_x`, `ft_print_u`, `ft_printf`|

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    📂 Functions <a id="functions"></a>
</h3>

---

<h3>
  <p align="center"> 
    <a href="#char">🧵 Character</a> • 
    <a href="#hexa">🔗 Hexadecimal</a> • 
    <a href="#pointer">🔧 Pointer</a> • 
    <a href="#unsigned">🔗 Unsigned</a> • 
    <a href="#string">🔗 String</a> • 
    <a href="#number">🔗 Number</a> • 
    <a href="#printf">🔗 Printf</a>
  </p>
</h3>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Print Character <a id="char"></a>
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
 
Operates similarly to the original libc function, writing the character c, but in addition it returns the number of characters written. Unlike `ft_putchar_fd`, which requires two parameters, `ft_putchar_v2` simplifies the process with just one, as it always directs output to `STDOUT` by default.   

| Project   |                Signature                |
|:----------|:----------------------------------------|
| ft_Printf | `int	ft_putchar_v2(char c)`        |


### General Functions  
- The functions under the General category contain the primary function for formatted output. The key function, `ft_printf`, reimplements the standard `printf` function in C, providing the ability to handle formatted output for different data types. It processes a variadic list of arguments and uses format specifiers like `%d`, `%s`, and `%x` to format strings, integers, and hexadecimal numbers.

### Print Functions  
- The Print category focuses on printing specific types of data, such as hexadecimal numbers, pointers, and unsigned integers. Functions like `print_hex_varargs` allow numbers to be printed in hexadecimal format, handling both lowercase and uppercase letters based on the format specifier. 
- The `print_pointer` function converts and prints a memory address in hexadecimal format, prefixed with `0x`, while `print_unsig` is responsible for printing unsigned integers. These functions are essential for handling specific formatting tasks that extend the functionality of `ft_printf`.

### Utility Functions  
- The Utility category provides helper functions that support the main printing and formatting operations. 
- Functions like `ck_format` are used to interpret the format specifiers passed to `ft_printf`, determining the correct output format for each argument. `print_hex_rec` is used to recursively convert and print numbers in hexadecimal format, while `unsig_number` calculates the number of digits in an unsigned integer, allowing for precise formatting. 
- Additionally, utility functions like `ft_putchar_v2`, `ft_putstr_v2`, and `ft_putnbr_v2` handle basic output operations, printing single characters, strings, and numbers to the standard output, respectively.


<p align="center">
<a href="">Next ➡️</a>
</p>

 

## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

A `Makefile` is provided to automate the compilation process. It includes the following rules:

- `all`: Compiles the library and generates the `libftprintf.a` file.
- `clean`: Removes object files.
- `fclean`: Removes object files and the library.
- `re`: Recompiles the entire project.
- `test`: Compiles the project and runs the test stored in `test/main.c`

To compile the library, simply run:
```bash
make
```

This will generate the `libftprintf.a` library, which can be linked in other projects to use the **ft_printf** function.

### Basic Usage

To use the **ft_printf** library in your C code, follow the steps below:

1. Include the header in your code:
    ```c
    #include "42_ft_Printf/printf/inc/ft_printf.h"
    ```

2. Compile your code with the library:
    ```bash
    cc -Wall -Wextra -Werror -o your_exec your_code.c  -L 42_ft_Printf/printf/ -lftprintf -L 42_Libft/libft/ -lft
    ```

3. You can now use the `ft_printf` function in your program as follows:
    ```c
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    ```

<!-- ## 🔠 Format Specifiers

The **ft_printf** project supports the following format specifiers:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a pointer in hexadecimal format.
- `%d`/`%i`: Prints a decimal integer.
- `%u`: Prints an unsigned decimal number.
- `%x`/`%X`: Prints a hexadecimal number (lowercase/uppercase letters).
- `%%`: Prints the percentage symbol. -->





























































# ft_printf_42

**ft_printf** is a simplified implementation of the `printf` function in C, providing basic formatting for characters, strings, integers, unsigned integers, hexadecimal, and pointers.



## Introduction

This project aims to provide a basic `printf` functionality with support for commonly used format specifiers. It's designed to be a learning exercise and may not cover all edge cases or features of a complete standard `printf` implementation.

## Usage

To use **ft_printf** in your C project, follow these steps:

1. Clone the repository: `git clone <repository-url>`
2. Include the `ft_printf.h` header file in your source code.
3. Compile your project with the `ft_printf` source files.

## Supported Format Specifiers

- `%c`: Character
- `%%`: Percent sign
- `%s`: String
- `%d`, `%i`: Signed integer
- `%u`: Unsigned integer
- `%x`: Hexadecimal (lowercase)
- `%X`: Hexadecimal (uppercase)
- `%p`: Pointer

## How to Build

To build the project, you can use a simple Makefile or compile the source files manually. Here's an example using GCC:

```bash
gcc -Wall -Wextra -Werror -c ft_printf.c ft_print_char.c ft_print_str.c ... # Add all source files
gcc -o your_program your_source_file.c ft_printf.o ft_print_char.o ft_print_str.o ... # Add all object files






