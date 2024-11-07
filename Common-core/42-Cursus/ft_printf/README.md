h1 align="center">ft_Printf</h1>
<p align="center"> 
 
<h3>
  <p align="center"> 
    <a href="#introduction">Introduction</a> • 
    <a href="#structure">Structure</a> • 
    <a href="#Docs">Docs</a> • 
    <a href="#Compilation">Compilation</a> • 

  </p>
</h3>

## 🗣️ Introduction <a id="introduction"></a>

This repository contains a custom implementation of the printf function, developed as part of the 42 School coding curriculum. The project, called ft_printf, aims to mimic the functionality of the standard C library’s printf function, providing a versatile tool for formatted output. This exercise not only reinforces core C programming concepts but also builds foundational skills in low-level coding and memory management.

The ft_printf project focuses on re-creating the behaviors of printf from scratch, requiring an in-depth understanding of several key concepts, including:

    String Handling: The function must manage strings efficiently, interpreting format specifiers embedded within them, and generating formatted output.
    Type Conversion and Output Formatting: The project involves handling multiple data types (like integers, characters, and strings) and applying various format specifiers (such as %d, %s, %x) to display values in specific formats, just as printf would.
    Versatile Use in Projects without the Standard Library: Since some projects in the 42 School curriculum do not permit the use of the standard C library, this implementation provides a custom alternative for formatted output, which can be reused in those scenarios.

By tackling this project, students gain practical insight into how printf operates under the hood, preparing them to approach more complex low-level programming challenges. The resulting ft_printf implementation supports a variety of format specifiers and data types, enabling formatted output with control over how different types of data are displayed.

## 🧬 Project Structure <a id="structure"></a>

The ft_printf project is structured around a central function, ft_printf, which is designed to handle multiple data types and formatting options, such as strings, integers, characters, and hexadecimal values. The main function interacts with a series of supporting functions, each specialized for processing and formatting specific types of data according to the required output format.

This modular approach allows ft_printf to interpret and format different types of input consistently, and each auxiliary function has a clear, focused role within the formatting pipeline. Together, these components provide a comprehensive custom implementation that mirrors much of the functionality of the standard printf function, making it versatile for use in projects that require formatted output without relying on external libraries.


## Directory Tree 

<pre>
ft_printf
├── includes
│   ├── ft_printf.h
│   └── libft.h
├── Libft
│   
├── Makefile
|
└── srcs
    ├── ft_print_c.c
    ├── ft_print_d.c
    ├── ft_printf.c
    ├── ft_print_p.c
    ├── ft_print_s.c
    ├── ft_print_u.c
    ├── ft_print_x.c
    └── ft_strlen.c

</pre>

> `/includes`: This directory contains the project header file.  
> `/srcs`: This directory contains the project's source code files.  

## Groups

|**General**|**Print**|
|:---------:|:-------:|
|`ft_printf`| `ft_print_c`, `ft_print_d`, `ft_print_u`, `ft_print_p`, `ft_print_x`, `ft_print_u`, `ft_printf`|


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
<a href="https://github.com/pin3dev/42_ft_Printf/wiki/ft_Printf">Next ➡️</a>
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

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Supported Format Specifiers](#supported-format-specifiers)
- [How to Build](#how-to-build)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

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


























<div align="center">
  
# <a href="#"><img width="500" align="center" src="https://github.com/user-attachments/assets/98c7b6ef-d3a8-425e-83c7-f118db56754e"></a> Cursus Common Core

The 42 Common Core is an intensive, self-taught, project-based curriculum focused on software development and problem-solving designed to build strong programming foundations. It emphasizes autonomy, collaboration, and adaptability.<br>

</div>

<div align="center">

<table>
  <tr>
    <th align="center"><a href="#"> <img width="30" align="center" src="https://github.com/user-attachments/assets/ac216672-a141-48be-bc53-ae13dd35c799"></a></th>
    <td align="center"> circle 0 </td>
    <td align="center"> circle 1 </td>
    <td align="center"> circle 2 </td>
    <td align="center"> circle 3 </td>
    <td align="center"> circle 4 </td>
    <td align="center"> circle 5 </td>
    <td align="center"> circle 6 </td>
  </tr>
  <tr>
    <td>pjcts
    </td>
    <td>

[**`libft`**](https://github.com/LLuisPP/42Cursus/tree/main/libft)
    </td>
    <td>

  [**`born2beRoot`**](https://github.com/LLuisPP/42Cursus/tree/main/Born2beRoot)<br>
  [**`ft_printf`**](https://github.com/LLuisPP/42Cursus/tree/main/ft_printf)<br>
  [**`get_next_line`**](https://github.com/LLuisPP/42Cursus/tree/main/get_next_line)
    </td>
    <td>

[**`push_swap`**](https://github.com/LLuisPP/42Cursus/tree/main/push_swap)<br>
[**`fractol`**](https://github.com/LLuisPP/42Cursus/tree/main/fractol)<br>
[**`pipex`**](https://github.com/LLuisPP/42Cursus/tree/main/pipex)
    </td>
    <td>

[**`philosophers`**](https://github.com/LLuisPP/42Cursus/tree/main/philosophers)<br>
[**`minishell`**](https://github.com/LLuisPP/42Cursus/tree/main/minishell)
    </td>
    <td>

[**`netpractice`**]()<br>
[**`miniRT`**]()<br>
[**`cpp`**]()
    </td>
    <td>

[**`ft_irc`**]()<br>
[**`inception`**]()<br>
[**`cpp`**]()
    </td>
    <td>

[**`trascendence`**]()<br>
    </td>
  </tr>
  <tr>
    <td>exam</td>
    <td></td>
    <td></td>
    <td>
      
[**`rank02`**](https://github.com/LLuisPP/42-Exams/tree/main/rank02)</td>
<td>
      
[**`rank03`**](https://github.com/LLuisPP/42-Exams-rank03)</td>
<td>
      
[**`rank04`**](https://github.com/LLuisPP/42-exams-rank04)</td>
<td>
      
[**`rank05`**]()</td>
<td>
  
[**`rank06`**]()</td>
  </tr>
</table>

</div>

<h2>Project overview:</h2>
<br>

<div align="center">

|<a href="https://github.com/LLuisPP/42Cursus/tree/main/"> <img width="30" align="center" src="https://github.com/user-attachments/assets/ac216672-a141-48be-bc53-ae13dd35c799"></a>|Project|Lvl|Description|OS|100|125|Date|
|---|---|---|:---|:---|:---|:---|---|
|`📖`|[**libft**](https://github.com/LLuisPP/42Cursus/tree/main/libft)|:suspect:| Essential C functions library replication |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen">|<a href="#"><img src="https://img.shields.io/badge/125-darkgreen"></a>|`Sep'23`|
||`milestone 0`|||||||
|`🐧`|[**born2beRoot**](https://github.com/LLuisPP/42Cursus/tree/main/Born2beRoot)|:hurtrealbad:| Configure a Linux virtual machine |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>|--|`Oct'23`|
|`🖨`|[**ft_printf**](https://github.com/LLuisPP/42Cursus/tree/main/ft_printf)|:rage2:| Create a printf function from scratch in C |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>|--|`Nov'23`|
|`📝`|[**get_next_line**](https://github.com/LLuisPP/42Cursus/tree/main/get_next_line)|:rage4:| Read file input line by line efficiently |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>|<a href="#"><img src="https://img.shields.io/badge/125-darkgreen"></a>|`Dic'23`|
||`milestone 1`|||||||
|`🔢`|[**push_swap**](https://github.com/LLuisPP/42Cursus/tree/main/push_swap)|:feelsgood:| Sort stack numbers with limited actions |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/86-darkgreen"></a>|--|`Feb'24`|
|`🌀`|[**fractol**](https://github.com/LLuisPP/42Cursus/tree/main/fractol)|:goberserk:| Generate 2D fractals with graphical output |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>|<a href="#"><img src="https://img.shields.io/badge/110-darkgreen"></a>|`Feb'24`|
|`🧪`|[**pipex**](https://github.com/LLuisPP/42Cursus/tree/main/pipex)|:finnadie:| Handle child process with forks and pipes |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/e728727c-b38b-48b8-92ad-b7006445f64d"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>|--|`May'24`|
|`🔖`|[**rank 02 exam**](https://github.com/LLuisPP/42-Exams/tree/main/rank02)|:goberserk:| Solve 4/57 exercises in 3 hours for 100 pts |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>||`Jul'24`|
||`milestone 2`|||||||
|`🔖`|[**rank 03 exam**](https://github.com/LLuisPP/42-Exams-rank03)| :godmode:| Rndm program: ft_printf or get_next_line |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>||`Aug'24`|
|`🍽`|[**philosophers**](https://github.com/LLuisPP/42Cursus/tree/main/philosophers)|:rage2:| Synchronize threads to solve philo problem |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|<a href="#"><img src="https://img.shields.io/badge/100-darkgreen"></a>|--|`Aug'24`|
|`📦`|[**minishell**](https://github.com/LLuisPP/42Cursus/tree/main/minishell)|:finnadie:| Build a functional shell similar to Bash |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|▶️|--|--|
||`milestone 3`|||||||
|`🔖`|[**rank 04 exam**](https://github.com/LLuisPP/42-Exams-rank04)|:rage2:| Develop a working microshell |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`🌐`|[**netpractice**]()|:suspect:| Practice networks through hands-on tasks |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`🌅`|[**miniRT**]()|:hurtrealbad:| Create a 3D scene renderer |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`📟`|[**cpp's 0-5**]()|:rage2:| Basics of C++ and its fundamental features |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
||`milestone 4`|||||||
|`👥`|[**inception**]()|:rage3:| Contain multiple Docker containers |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`💬`|[**ft_irc**]()|:rage4:| Implement a functional IRC server |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`📟`|[**cpp's 6-9**]()|:finnadie:| Explore advanced C++ and STL |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`🔖`|[**rank 05 exam**]()|:godmode:| Assessment of skills in C and C++ |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
||`milestone 5`|||||||
|`🕹️`|[**trascendence**]()|:finnadie:| Create a 2D online game with diverse mechanics |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|
|`🔖`|[**rank 06 exam**]()|:godmode:| Advanced level exam in C/C++ |<div align="center"><a href="#"><img width="20" src="https://github.com/user-attachments/assets/a8c3a3ed-deb0-48a8-a12e-7ecdb5b7d164"></a></div>|--|--|`'24`|

</div>
<div align="left">
When I finish everything, it will be:
</div>
<br>
<div align="center">
<a href="#"><img width="408" align="center" src="https://github.com/user-attachments/assets/bf7526e2-1027-42c9-9597-4f8b6d9527f9"></a>
</div>

<h2>Cursus holygraph</h2>

<div align="left">
The Holygraph is a visual tool used at 42 to track students' progress over time, showing their project completions and skill development.
</div>
<br>
<div align="center">
<a href="#"><img width="408" align="center" src="https://github.com/user-attachments/assets/b4e0e4f1-8eb9-4e21-9e1c-a7cc36ae18dc"></a> <a href="#"><img width="400" align="center" src="https://github.com/user-attachments/assets/34bf2383-b6b2-488d-b6b9-582c8c7c06ad"></a>
</div>






