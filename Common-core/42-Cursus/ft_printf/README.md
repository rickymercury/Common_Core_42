![](https://github.com/rickymercury/banners/blob/main/github_piscine_and_common_core_banner_ft_printf(1).png
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
    <a href="#integer">🔗 Integer</a> • 
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
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#memory">Hexadecimal ➡️</a>
</p>
</h3>

---


| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_print_c`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_print_c)| `int	ft_print_c(int c)`                 |


---

The `ft_print_c` function itself is responsible for printing a single character to the standard output. It receives a character, prints it using the write function, and returns the value 1 to indicate that one character has been written. This return value is important because it contributes to the total count of characters printed by ft_printf, which is a central requirement of the project.

Within ft_printf, `ft_print_c` is called from the `format_printf` function when the format specifier is `%c`. 
This flow is designed to handle various types of data seamlessly, and here is how it unfolds in detail:

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Format Parsing:
</h3>

ft_printf processes the input string character by character. As it scans through the characters, it checks for occurrences of the % symbol, which indicates the beginning of a format specifier.
    
<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to handle_format:
</h3>

---

When ft_printf detects a format specifier, it calls the handle_format function, passing along the argument list and the current format specifier (e.g., %c, %s, %d, etc.). 
This function’s role is to determine which specific printing function to call based on the format character. 
For instance, if the format character is 'c', it will direct the program to ft_print_c.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling ft_print_c:
</h3>

Once handle_format has determined that the format is %c, format_printf invokes ft_print_c with the appropriate argument.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Printing and Counting:
</h3> 

Within ft_print_c, the write function is used to print the character to the standard output. 
For instance, write(1, &c, 1) writes a single character (stored in c) to the output. ft_print_c then returns 1, which represents the number of characters printed by this function. 
This return value is essential for ft_printf’s overall functionality, as it adds up each function’s return values to provide the total character count of the formatted output. 

---

With ft_print_c, ft_printf can handle the `%c` format, enabling the printing of individual characters in an efficient and organized way.

---

>
> Example of How ft_printf Uses ft_print_c
>
> Consider the following examples demonstrating how ft_printf interacts with ft_print_c:
>
> Example 1:          ft_printf("Character: %c", 'X');
>
> - ft_printf detects %c and calls handle_format.
> - handle_format identifies the %c format specifier and calls ft_print_c('X').
> - ft_print_c writes X to the output and returns 1.
> - The total output is "Character: X", and ft_printf returns 12 (11 characters for "Character: X" plus 1 for the newline).
>
> Example 2:          ft_printf("First: %c, Second: %c", 'A', 'B');
>
> - ft_printf processes %c twice: once for 'A' and once for 'B'.
> - Each %c calls handle_format, which routes to ft_print_c.
> - ft_print_c first prints A and returns 1, then prints B and returns 1.
> - The final output is "First: A, Second: B", and ft_printf returns 19 (total character count of the output string).

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Print Hexadecimal <a id="hexa"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#structure">⬅️ Character</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#pointer">Pointer ➡️</a>
</p>
</h3>

---

| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_print_x`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_print_x)| `int	ft_print_x(unsigned int x, int upper)`                 |

---

The `ft_print_x` function is designed to handle the `%x` and `%X` format specifiers within the custom ft_printf implementation,  which represent unsigned integers in hexadecimal format.
These specifiers allow ft_printf to format integers as hexadecimal values, a common requirement for displaying memory addresses, binary data, and other low-level information in human-readable form.

Within `ft_printf`, the `%x` and `%X` specifiers are detected in a sequence of operations that follow a similar structure to other format specifiers:

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Format Parsing:
</h3>

As ft_printf reads through its input string, it searches for the % character, indicating that a format specifier is present. 
For example, in ft_printf("Value: %x", 255);, the %x sequence signals that an integer argument should be printed in hexadecimal.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to handle_format:
</h3>

Once a format specifier is identified, ft_printf calls format_printf, passing along the current format character (in this case, 'x' or 'X') and the list of arguments.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling ft_print_p:
</h3>

If the format character is 'x', format_printf calls ft_print_x, passing the next argument as an unsigned integer along with 0 for the upper parameter, indicating that lowercase hexadecimal should be used.
If the format character is 'X', format_printf again calls ft_print_x, but this time with upper set to 1, indicating uppercase format.

---

This function, along with its helper functions `ft_isdigit`, `is_lowercase`, and `add_hex`, provides functionality for printing hexadecimal numbers in both lowercase and uppercase, according to the specified format.

---

`is_lowercase`: 

This helper function, checks if a character a is a lowercase letter between 'a' and 'f'. It returns 1 if a is lowercase, allowing for conditional handling of lowercase hexadecimal digits when uppercasing might be necessary.

`add_hex`: 
    
This function is responsible for writing individual hexadecimal characters to the output, converting them to uppercase if required.

Uses a predefined hexadecimal string hex = "0123456789abcdef" to select the appropriate character based on x % 16.
If the character is a lowercase hexadecimal letter (a to f) and is not a digit, add_hex converts it to uppercase by subtracting 32 (following ASCII value conversion).
It then writes either the uppercase or original lowercase character to the output.

`ft_print_x`: 

The core function, ft_print_x, recursively prints an unsigned integer x in hexadecimal format. It includes an upper parameter that indicates whether the output should be uppercase. 

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Recursive Division:
</h3> 

If x is greater than or equal to 16, ft_print_x recursively divides x by 16 to process higher-order digits first. This recursive call structure ensures the digits are printed in the correct order from most significant to least significant.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling add_hex or Writing Lowercase Directly:
</h3>

If the upper flag is set, add_hex is called to potentially convert lowercase letters (a to f) to uppercase as needed. If upper is not set, it writes the character directly from the hex array in lowercase.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Character Count:
</h3>

After each character is written, the function increments count, which keeps track of the total number of characters printed. This count is returned as the function's output, representing the total length of the hexadecimal representation printed.

The ft_print_x function then prints the unsigned integer in hexadecimal format based on the upper flag

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Lowercase (%x):
</h3> 

If upper is 0, ft_print_x uses lowercase hexadecimal digits (0-9, a-f) for conversion, suitable for the %x format.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Uppercase (%X):
</h3>

If upper is 1, ft_print_x calls add_hex to convert any lowercase letters in the range a-f to uppercase, ensuring correct output for %X.

---

> Examples of ft_print_x
>
> Example 1:         ft_printf("Hexadecimal: %x", 255);
>
> - %x is detected, and ft_print_x is called with upper = 0.
> - The output will be "Hexadecimal: ff", as ft_print_x prints 255 in lowercase hexadecimal.
> - The return value from ft_printf would be 15, counting all characters printed.
>
> Example 2:          ft_printf("Uppercase Hex: %X", 255);
>
> - %X is detected, and ft_print_x is called with upper = 1.
> - The output will be "Uppercase Hex: FF", as ft_print_x capitalizes f to F.
> - The total character count returned by ft_printf is 15.
 
---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Print Pointer <a id="pointer"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#hexa">⬅️ Hexadecimal</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#unsigned">Unsigned ➡️</a>
</p>
</h3>

---

| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_print_p`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_print_p)| `int ft_print_p(unsigned long long ptr)`                 |

---

The `ft_print_p` function is designed to handle the `%p` format specifier within the custom ft_printf implementation, which is specifically used for displaying memory addresses in a hexadecimal format prefixed with "0x". This format specifier is crucial for representing pointers in a standardized manner, allowing users to see the memory location of a variable in human-readable form.

Within ft_printf, the `%p` specifier is detected and processed similarly to other format specifiers, following a sequence of operations to correctly output the pointer address in hexadecimal format:

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Format Parsing:
</h3>
   
As ft_printf reads through its input string, it searches for the % character, signaling the presence of a format specifier. 
For instance, in ft_printf("Pointer: %p", ptr), the %p indicates that a pointer argument should be printed in hexadecimal.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to handle_format:
</h3>

As ft_printf reads through its input string, it searches for the % character, signaling the presence of a format specifier. For instance, in ft_printf("Pointer: %p", ptr), the %p indicates that a pointer argument should be printed in hexadecimal.
Once the %p specifier is identified, ft_printf calls format_printf, passing the format character 'p' and the argument list to handle the pointer format.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling ft_print_p:
</h3>

When the format character is `%p`, format_printf calls ft_print_p with the provided pointer argument. ft_print_p then converts and outputs the pointer value in the 0x... format.

---

This function, together with its helper functions `p_digits` and `print_ptr_rec`, provides the necessary operations to print pointer addresses in a consistent hexadecimal format.

`p_digits`: 

This helper function calculates the number of hexadecimal digits required to represent the pointer address. It accepts n, the pointer address in unsigned long long format, and returns the number of digits necessary.
If n is 0, p_digits returns 1, as even a zero address requires a single character.
If n is non-zero, it divides n by 16 in a loop, counting the number of divisions until n becomes 0, which corresponds to the number of hexadecimal digits.

`print_ptr_rec`: 

This recursive function handles the actual printing of each hexadecimal digit of the pointer address in lowercase.
If ptr is 16 or greater, it recursively calls itself with ptr / 16, processing the higher-order digits first.
The function uses "0123456789abcdef" to select the appropriate hexadecimal character for ptr % 16, assigns it to hex_digit, and then prints it with ft_print_c.
This recursion ensures the digits are printed in the correct order, from most significant to least significant.

`ft_print_p`: 

This is the main function called to handle the %p format. It organizes the pointer representation in the "0x..." format:
If ptr is 0, it outputs "(nil)" to represent a null pointer, consistent with standard C printf behavior.
If ptr is not 0, ft_print_p writes the "0x" prefix to indicate a hexadecimal pointer, then calls print_ptr_rec to output each hexadecimal digit.
It calculates the total length of the printed output by adding 2 for "0x" and the digit count from p_digits, returning this value as the function's output.

---

> Examples of ft_print_p
>
> Example 1:        ft_printf("Address: %p", ptr);
>
> - When %p is detected, ft_print_p is called with the pointer value.
> - For a pointer address 0x7ffee3b1a5c8, ft_print_p outputs "0x7ffee3b1a5c8".
> - It writes "0x" as the prefix, then calls print_ptr_rec to print each hexadecimal digit.
> - The total character count returned includes 2 for "0x" plus the number of digits in p_digits(ptr).
>
> Example 2:         ft_printf("Pointer is %p", 0);
>
> - When the pointer value is 0, ft_print_p outputs "(nil)".
> - The total count returned by ft_print_p is 5, representing "(nil)".

---

By handling the %p specifier in this structured way, ft_printf can accurately output pointer addresses in hexadecimal notation, providing consistent and human-readable memory addresses.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Print Integer <a id="integer"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#pointer">⬅️ Pointer</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#unsigned">Unsigned ➡️</a>
</p>
</h3>

---

| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_print_d`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_print_d)| `int	ft_print_d(int n)`                 |

---

The `ft_print_d` function is designed to handle the `%d` and `%i` format specifiers within the custom ft_printf implementation, which represent signed decimal integers. This function is essential for formatting integers in base 10, a common requirement in many applications where numeric values need to be displayed.

Within ft_printf, the `%d` and `%i` specifiers are handled through a sequence of steps that identify and process these format specifiers to correctly display signed integers.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Format Parsing:
</h3>

As ft_printf parses the input string, it searches for the % character, which indicates a format specifier. 
For example, in ft_printf("Value: %d", -123);, the %d sequence signals that an integer argument should be printed as a signed decimal.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to handle_format:
</h3>

When ft_printf identifies the %d or %i specifier, it calls format_printf, passing the format character ('d' or 'i') and the argument list.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling ft_print_d:
</h3>

If the format character is %d or %i, format_printf calls ft_print_d with the integer argument. ft_print_d then handles the conversion and output of the integer in decimal format.

---

The ft_print_d function relies on the helper function negative to manage negative values and uses an array of digits to construct and print each decimal digit from most significant to least significant.

`negative`: 

This helper function checks if the integer is negative, printing a minus sign if necessary and converting the integer to a positive equivalent.
It accepts pointers to number and count. 
If *number is negative, negative writes '-' to indicate the negative sign, converts *number to its positive equivalent, and increments *count to account for the printed minus sign.

`ft_print_d`: 

The main function, ft_print_d, handles the conversion and output of the integer in decimal format.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Special Case for Minimum Integer Value:
</h3>

If n is -2147483648 (the minimum 32-bit integer value), ft_print_d returns "-2147483648" directly by calling ft_print_s. 
This is necessary because negating this value would exceed the range of a signed 32-bit integer.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Negative Number Handling:
</h3>

For all other negative values, ft_print_d calls negative to print the minus sign if n is negative and to convert n to positive.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Zero Check:
</h3>

If n is 0, ft_print_d directly prints '0' by calling ft_print_c and returns, as no further processing is required for zero.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Digit Extraction:
</h3>

For non-zero values, ft_print_d breaks down the integer into individual digits by repeatedly dividing n by 10 and storing each remainder (the last digit of n) in the digits array. count is incremented for each extracted digit.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Printing Digits in Correct Order:
</h3>
   
Once all digits are stored in reverse order, ft_print_d iterates through digits from the highest index down to 0, printing each digit in the correct order by calling ft_print_c with the character representation of each digit (digits[i] + '0').

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Return Total Count:
</h3>

Finally, ft_print_d returns count, representing the total number of characters printed.

---

> Examples of ft_print_d
>
> Example 1:         ft_printf("Integer: %d", 123);
>
> - %d is detected, and ft_print_d is called with 123.
> - The output will be "Integer: 123", with ft_print_d printing each digit sequentially.
> - The total character count returned by ft_printf would be 11, accounting for all characters printed.
>
> Example 2:         ft_printf("Negative: %d", -456);
>
> - %d is detected, and ft_print_d is called with -456.
> - ft_print_d prints '-' using negative, then prints each digit in 456.
> - The output will be "Negative: -456", with ft_printf returning 12 as the total count.

---

This implementation of ft_print_d ensures that signed integers are correctly formatted and printed, accounting for both positive and negative values. It integrates seamlessly into ft_printf, enhancing its ability to handle various numeric types in formatted output.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Print Unsigned <a id="unsigned"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#integer">⬅️ Integer</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#string">String ➡️</a>
</p>
</h3>

---

| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_print_u`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_print_u)| `int ft_print_u(unsigned int n)`                 |

---

The `ft_print_u` function is designed to handle the `%u` format specifier within the custom ft_printf implementation, which is used for printing unsigned decimal integers. This format specifier is crucial for displaying non-negative integer values without any sign, making it a common requirement in applications that work with unsigned data types.

Within ft_printf, the `%u` specifier is handled similarly to other format specifiers, ensuring that unsigned integers are correctly formatted and printed.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Format Parsing:
</h3>

As ft_printf reads through the input string, it searches for the % character, indicating the presence of a format specifier. For example, in ft_printf("Value: %u", 123);, the %u sequence signals that an unsigned integer argument should be printed in decimal format.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to handle_format:
</h3>

When the %u specifier is identified, ft_printf calls format_printf, passing the format character 'u' and the argument list.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling ft_print_u:
</h3>

If the format character is %u, format_printf calls ft_print_u with the unsigned integer argument. ft_print_u then handles the conversion and output of the integer in decimal format, ensuring it is printed as an unsigned value.

---

The ft_print_u function uses a helper function `count_digits` to count the number of digits in the unsigned integer and recursively prints each digit.

`count_digits`: 

This helper function calculates how many digits are required to represent the unsigned integer nbr.
If nbr is 0, it returns 1 because even a zero number requires one character to display ('0').
For all non-zero values, it divides nbr by 10 repeatedly in a loop, incrementing the count for each division. 
This loop ensures that the number of digits is counted correctly.

`ft_print_u`: 

The main function, ft_print_u, is responsible for converting and printing the unsigned integer in decimal format.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Zero Check:
</h3>

If nbr is 0, ft_print_u directly prints the character '0' by calling ft_print_c and returns 1, as one character is printed.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Digit Count Calculation:
</h3>

If nbr is non-zero, ft_print_u calls count_digits to determine the number of digits in nbr. This function returns the total number of digits, which is then used to track the number of characters printed.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Recursive Division:
</h3>

If nbr is greater than or equal to 10, ft_print_u recursively calls itself with nbr / 10 to print higher-order digits first. 
This ensures that digits are printed in the correct order (from most significant to least significant).

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Printing Digits:
</h3>

After handling the recursive calls, ft_print_u prints the least significant digit by using ft_print_c(nbr % 10 + '0'). This converts the integer digit into its character equivalent (by adding the ASCII value of '0') and prints it.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Return Digit Count:
</h3>

Finally, ft_print_u returns digit_count, which represents the total number of digits in the unsigned integer. 
This value helps ft_printf track how many characters have been printed.

---

> Examples of ft_print_u
>
> Example 1:        ft_printf("Unsigned: %u", 123);
>
> - %u is detected, and ft_print_u is called with 123.
> - The function prints each digit recursively, eventually printing "123".
> - The total character count returned by ft_printf would be 9, accounting for the characters "Unsigned: " plus the digits printed.
>
> Example 2:        ft_printf("Zero: %u", 0);
>
> - %u is detected, and ft_print_u is called with 0.
> - ft_print_u prints the character '0' and returns 1.
> - The output will be "Zero: 0", and the total character count returned is 6.

---

This implementation of ft_print_u ensures that unsigned integers are correctly formatted and printed as decimal numbers. It integrates smoothly into ft_printf, extending the function's capabilities to handle unsigned data types.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Print String <a id="string"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#string">⬅️ String</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#printf">Printf ➡️</a>
</p>
</h3>

---

| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_print_s`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_print_s)| `int	ft_print_s(const char *str)`                 |

---

The `ft_print_s` function is designed to handle the %s format specifier within the custom ft_printf implementation. This specifier is used to print a string of characters, and it is one of the most common format specifiers encountered in formatted output functions.

Within ft_printf, the %s specifier is processed as follows:

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Format Parsing:
</h3>

ft_printf reads through the input string, looking for the % character to identify a format specifier. For example, in the call ft_printf("Hello, %s!", "world");, the %s sequence signals that the following argument is a string that needs to be printed.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to handle_format:
</h3>

Once %s is identified, ft_printf calls format_printf, passing the format character 's' and the argument list.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Calling ft_print_s:
</h3>

When the format character is %s, format_printf invokes ft_print_s, passing the string argument. ft_print_s handles the printing of the string, ensuring that each character is output correctly.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Null String Handling:
</h3>

If the provided string str is NULL, ft_print_s prints the string "(null)". This is a common practice to handle cases where a NULL pointer is passed as a string argument, providing a user-friendly output instead of potentially causing undefined behavior or crashes.
The string "(null)" is printed character by character using a loop, and each character is printed using the ft_print_c function. The count is incremented each time a character is printed.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    String Printing:
</h3>

If the provided string str is not NULL, the function enters a loop to print each character in the string.
The loop iterates over the characters of str one by one, calling ft_print_c to print each character.
The count variable is incremented each time a character is printed to keep track of the total number of characters printed.

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Return Value:
</h3>

The function returns count, which represents the total number of characters printed. This value is crucial for ft_printf to determine how many characters were output during the execution of the format string.

---

> Examples of ft_print_s
>
> Example 1:       ft_printf("String: %s", "Hello!");
>
> - %s is detected, and ft_print_s is called with the string "Hello!".
> - The function prints each character in "Hello!" using ft_print_c, resulting in the output "String: Hello!".
> - The return value from ft_printf will be 15, counting all characters, including "String: " and "Hello!".
>
> Example 2:       ft_printf("String: %s", NULL);
>
> - %s is detected, and ft_print_s is called with NULL as the argument.
> - The function prints the string "(null)" to handle the NULL string case.
> - The return value from ft_printf will be 9, as "(null)" consists of 9 characters.

---

By printing each character of the string individually and returning the correct count of printed characters, it integrates seamlessly into the overall ft_printf function, ensuring robust and flexible string formatting.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Printf <a id="printf"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#integer">⬅️ Integer</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#printf">Printf ➡️</a>
</p>
</h3> 

---

| Function   |                Signature                |
|:-----------|:----------------------------------------|
| [`ft_printf`](https://github.com/rickymercury/Common_Core_42/tree/main/Common-core/42-Cursus/ft_printf/srcs/Study/ft_printf)| `int ft_printf(const char *format, ...)`                 |

---

The format_`printf`, `handle_format`, and `ft_printf` functions work together in harmony to implement a custom version of `printf`, capable of handling multiple format specifiers and their respective arguments. Below is an in-depth explanation of how these functions operate and why they are effective and reliable in the context of the overall ft_printf function.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    format_printf Function
</h3>

The format_printf function is a core component responsible for interpreting the format specifiers and delegating the printing task to the appropriate helper function based on the format character.

## Input: 
It takes a va_list (args) containing the arguments passed to ft_printf, and a char (format), which represents the current format specifier (e.g., 'c', 's', 'd').

## Processing: 
The function uses a series of if-else conditions to check which format specifier is passed in the format argument.
If the specifier is c, ft_print_c is called with the next argument (va_arg(args, int)).
If it's s, ft_print_s is called with a const char *.
The function handles other specifiers like d, i, u, p, and x, passing appropriate arguments to their respective functions.
For %, ft_print_c('%') is invoked to print the literal % character.

## Return:
It returns the number of characters printed by the respective function. If no recognized format specifier is found, the function returns 0.

---

>Example:
>
> - If format = 'd', the ft_print_d function will be called, which is designed to handle integer formatting. 
> - The function then prints the integer value and returns the character count.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    handle_format Function
</h3>

The handle_format function is responsible for checking the current character from the format string to determine if it's a valid format specifier. If it is, it calls format_printf to delegate the actual printing.

## Input:
It takes a va_list (args), the format string (str), and an index pointer (i) which tracks the current position in the format string.

## Processing: 
The function checks if the current character str[*i] is one of the supported format specifiers (c, s, p, d, i, u, x, X, %).
If it is, format_printf is called with the respective arguments and the format character.
If it's not a valid format specifier, the function prints the percent sign (%) and the current character using ft_print_c.
This ensures that the format string is correctly printed even if it contains unknown characters or misplaced percent signs.

## Return:
The function returns the total number of characters printed, which includes both the format specifier handling and any non-format characters printed directly.

---

> Example:
>
> - If str[i] = 'd', handle_format calls format_printf(args, 'd') to print the integer argument passed to ft_printf. 
> - If the character isn't a format specifier, the function prints the character % followed by the character at str[i].

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    ft_printf Function
</h3>

The ft_printf function is the main function that is responsible for parsing the format string, identifying format specifiers, and printing the formatted output.

## Input: 
It takes a constant format string (format) and a variable number of arguments (...), passed using va_list.

## Processing: 
The function starts by checking if format is NULL. If it is, it returns -1 to indicate an error.
The va_list is initialized with va_start, and the function enters a loop to process each character of the format string.
If a % character is encountered, the function increments the index (i) and passes control to handle_format to process the format specifier.
If a non-format character is encountered, the function prints it using ft_print_c.

## Return:
The function returns the total number of characters printed.

---

> Example:
>
> - If the format string is "Hello %s!" and the argument is "world", the function will print "Hello world!". The function will return the total number of characters printed, which is 13 in this case.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    How These Functions Work Together
</h3>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Parsing the Format String:
</h3>

 `ft_printf` reads the format string character by character, handling non-format characters directly by calling `ft_print_c`.
  When it encounters a `%` character, it identifies a format specifier and calls `handle_format`.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Delegation to the Appropriate Printing Function:
</h3>

 `handle_format` passes the format specifier to `format_printf`, which then calls the appropriate function based on the specifier (such as `ft_print_c`, `ft_print_s`, `ft_print_d`, etc.).

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Printing and Character Counting:
</h3>

Each helper function, such as ft_print_c, ft_print_s, or ft_print_d, is responsible for printing the specific type of data and returning the number of characters printed.
This count is aggregated by ft_printf to provide the total length of the output.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Error Handling and Flexibility:
</h3>

If an unrecognized character or format specifier is encountered, handle_format prints the character % followed by the invalid specifier, ensuring that the function handles edge cases gracefully without crashing.
The code includes provisions for NULL strings and invalid format specifiers, ensuring that ft_printf behaves as expected even in edge cases.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    Effectiveness
</h3>
 
Each function is focused on a specific task (parsing format specifiers, printing characters, handling different types of arguments), making the code modular and easy to maintain.    

---

The format_printf, handle_format, and ft_printf functions together create an efficient, modular, and reliable implementation of printf. They correctly handle multiple format specifiers, print the respective data types, and count the number of characters printed. The error handling ensures robustness, and the overall structure allows for future extensions, making this implementation an effective and infallible part of the ft_printf function.

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🕹️ Compilation and Usage <a id="compilation"></a>
</h3>

---

<h3>
<p align="center">
  <a href="#integer">⬅️ Integer</a> • 
  <a href="#functions">⬆️ Functions</a> • 
  <a href="#ft_printf">⬆️ ⬆️ Top</a> • 
  <a href="#compilation">Compilation ➡️</a>
</p>
</h3>

---

<h3 align="center" style="font-size: 2.5em; font-weight: bold; color: #2C3E50;">
    🕹️ Makefile <a id="compilation"></a>
</h3>


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


A `Makefile` is provided to automate the compilation process. It includes the following rules:

- `all`: Compiles the library and generates the `libftprintf.a` file.
- `clean`: Removes object files.
- `fclean`: Removes object files and the library.
- `re`: Recompiles the entire project.

To compile the library, simply run:
```bash
make
```

This will generate the `libftprintf.a` library, which can be linked in other projects to use the **ft_printf** function.






