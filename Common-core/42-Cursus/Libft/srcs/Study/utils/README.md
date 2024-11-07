<h1 align="center">Utils</h1>

## `ft_isalpha`

> Mimics `isalpha` function:  
Checks whether the passed character is an alphabetic letter.

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int isalpha(int c);`                                                                            |
| **Parameters** | `c`: Character to be checked.                                                                    |
| **Return**     | Non-zero if the character is an alphabetic letter, zero otherwise.                               |
| **Manual**     | [isalpha(3) - Linux Manual](https://man7.org/linux/man-pages/man3/isalpha.3.html)                |

#### **Usage Example:**

```c
int result = isalpha('A'); // Returns non-zero
int result = isalpha('1'); // Returns 0
```

---

## `ft_isdigit`

> Mimics `isdigit` function:  
Checks whether the passed character is a decimal digit (0-9).

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int isdigit(int c);`                                                                            |
| **Parameters** | `c`: Character to be checked.                                                                    |
| **Return**     | Non-zero if the character is a decimal digit (0-9), zero otherwise.                               |
| **Manual**     | [isdigit(3) - Linux Manual](https://man7.org/linux/man-pages/man3/isdigit.3.html)                |

#### **Usage Example:**

```c
int result = isdigit('5'); // Returns non-zero
int result = isdigit('a'); // Returns 0
```

---

## `ft_isalnum`

> Mimics `isalnum` function:  
Checks whether the passed character is alphanumeric (either a digit or a letter).

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int isalnum(int c);`                                                                            |
| **Parameters** | `c`: Character to be checked.                                                                    |
| **Return**     | Non-zero if the character is alphanumeric, zero otherwise.                                        |
| **Manual**     | [isalnum(3) - Linux Manual](https://man7.org/linux/man-pages/man3/isalnum.3.html)                |

#### **Usage Example:**

```c
int result = isalnum('A'); // Returns non-zero
int result = isalnum('1'); // Returns non-zero
int result = isalnum('$'); // Returns 0
```

---

## `ft_isascii`

> Mimics `isascii` function:  
Checks whether the passed character is an ASCII character (0-127).

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int isascii(int c);`                                                                            |
| **Parameters** | `c`: Character to be checked.                                                                    |
| **Return**     | Non-zero if the character is an ASCII character, zero otherwise.                                  |
| **Manual**     | [isascii(3) - Linux Manual](https://man7.org/linux/man-pages/man3/isascii.3.html)                |

#### **Usage Example:**

```c
int result = isascii(65);  // Returns non-zero for 'A'
int result = isascii(200); // Returns 0
```

---

## `ft_isprint`

> Mimics `isprint` function:  
Checks whether the passed character is printable, including space.

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int isprint(int c);`                                                                            |
| **Parameters** | `c`: Character to be checked.                                                                    |
| **Return**     | Non-zero if the character is printable, zero otherwise.                                           |
| **Manual**     | [isprint(3) - Linux Manual](https://man7.org/linux/man-pages/man3/isprint.3.html)                |

#### **Usage Example:**

```c
int result = isprint(65);  // Returns non-zero for 'A'
int result = isprint(127); // Returns 0 (non-printable)
```

---

## `ft_toupper`

> Mimics `toupper` function:  
Converts a lowercase alphabetic character to uppercase.

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int toupper(int c);`                                                                            |
| **Parameters** | `c`: Character to be converted.                                                                  |
| **Return**     | Uppercase equivalent if `c` is lowercase; otherwise returns `c`.                                  |
| **Manual**     | [toupper(3) - Linux Manual](https://man7.org/linux/man-pages/man3/toupper.3.html)                |

#### **Usage Example:**

```c
int upper = toupper('a'); // Returns 'A'
int unchanged = toupper('A'); // Returns 'A'
```

---

## `ft_tolower`

> Mimics `tolower` function:  
Converts an uppercase alphabetic character to lowercase.

#### Original Function:
| **Library**    | `<ctype.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int tolower(int c);`                                                                            |
| **Parameters** | `c`: Character to be converted.                                                                  |
| **Return**     | Lowercase equivalent if `c` is uppercase; otherwise returns `c`.                                  |
| **Manual**     | [tolower(3) - Linux Manual](https://man7.org/linux/man-pages/man3/tolower.3.html)                |

#### **Usage Example:**

```c
int lower = tolower('A'); // Returns 'a'
int unchanged = tolower('a'); // Returns 'a'
```

---

## `ft_atoi`

> Mimics `atoi` function:  
Converts a string to an integer, ignoring leading whitespace and stopping conversion at the first non-numeric character.

#### Original Function:
| **Library**    | `<stdlib.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int atoi(const char *str);`                                                                      |
| **Parameters** | `str`: The string to convert.                                                                     |
| **Return**     | The integer value of the string, or 0 if no valid conversion is performed.                        |
| **Manual**     | [atoi(3) - Linux Manual](https://man7.org/linux/man-pages/man3/atoi.3.html)                      |

#### **Usage Example:**

```c
int number = atoi("42");      // Returns 42
int number = atoi("   -42");  // Returns -42
int number = atoi("42abc");   // Returns 42
```

#### **Specifics:**

> `atoi` does not handle overflow or underflow. For large inputs, it may result in undefined behavior.

```c
int number = atoi("999999999999999999999999"); // Undefined behavior, may overflow
```

---

## `ft_itoa`

> Description:  
Creates a string representing the integer received as an argument.

| **Signature**        | `char *ft_itoa(int n);`                                                                         |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `n`: The integer to convert into a string.                                                       |
| **Return value**     | A newly allocated string representing the integer. Returns `NULL` if the allocation fails.        |
| **Equivalent**       | C++11 have similar behavior using methods like `std::to_string()` to convert integers to strings.|          

#### **Usage Example:**

```c
char *str = ft_itoa(1234); // Converts the integer 1234 into the string "1234"
```

#### **Specifics:**

> `ft_itoa` allocates memory for the string, so the returned string must be freed after use.

```c
char *str = ft_itoa(42);
free(str); // Freeing the allocated memory
```

---


## `ft_putchar_fd`

> Description:  
Writes the character `c` to the given file descriptor.

| **Signature**        | `void ft_putchar_fd(char c, int fd);`                                                           |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `c`: The character to output.                                                                    |
|                      | `fd`: The file descriptor on which to write.                                                     |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | In C, the `write(2)` function can be used to write directly to a file descriptor.                |                      

#### **Usage Example:**

```c
ft_putchar_fd('A', 1); // Outputs 'A' to the standard output (file descriptor 1)
```

---

## `ft_putstr_fd`

> Description:  
Writes the string `s` to the given file descriptor.

| **Signature**        | `void ft_putstr_fd(char *s, int fd);`                                                            |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s`: The string to output.                                                                       |
|                      | `fd`: The file descriptor on which to write.                                                     |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | None.                                                                                           |

#### **Usage Example:**

```c
ft_putstr_fd("Hello, World!", 1); // Outputs "Hello, World!" to standard output (fd 1)
```

---

## `ft_putendl_fd`

> Description:  
Writes the string `s` to the given file descriptor, followed by a newline.

| **Signature**        | `void ft_putendl_fd(char *s, int fd);`                                                          |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s`: The string to output.                                                                       |
|                      | `fd`: The file descriptor on which to write.                                                     |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | None.                                                                                            |

#### **Usage Example:**

```c
ft_putendl_fd("Hello, World!", 1); // Outputs "Hello, World!\n" to standard output (fd 1)
```

---

## `ft_putnbr_fd`

> Description:  
Writes the integer `n` to the given file descriptor.

| **Signature**        | `void ft_putnbr_fd(int n, int fd);`                                                             |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `n`: The integer to output.                                                                      |
|                      | `fd`: The file descriptor on which to write.                                                     |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | None.                                                                                            | 

#### **Usage Example:**

```c
ft_putnbr_fd(1234, 1); // Outputs "1234" to standard output (fd 1)
```

---

<p align="center">
<a href="https://github.com/pin3dev/42_Libft/wiki/Home"> Previous ⬅️ </a>• 
<a href="#strings"> Top ⬆️ </a>• 
<a href="https://github.com/pin3dev/42_Libft/wiki/Additional">Next ➡️ </a>
</p>