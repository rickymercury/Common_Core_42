<h1 align="center">Strings</h1>

<p align="center">
<a href="#memory">Memory</a>• 
<a href="#utils">Utils</a>
</p>

## `ft_strlen`

> Mimics `strlen` function:  
Calculates the length of a string, i.e., the number of characters before the null terminator (`\0`).  
The null terminator is not included in the length.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `size_t strlen(const char *s);`                                                                  |
| **Parameters** | `s`: Pointer to the string whose length will be counted.                                         |
| **Return**     | The length of the string as a `size_t` value, excluding the null terminator (`\0`).              |
| **Manual**     | [strlen(3) - Linux Manual](https://man7.org/linux/man-pages/man3/strlen.3.html)                  |

#### **Usage Example:**

```c
size_t len = strlen("Hello, World!"); // Returns 13
size_t len_empty = strlen("");        // Returns 0
size_t len_null_char = strlen("\0");  // Returns 0
```

#### **Specifics:**

> No explicit check for `NULL` is made in the original function.

```c
char *str = NULL;
size_t len = strlen(str); // Undefined behavior
```

> No explicit check for the null terminator (`\0`) at the end of the buffer is made in the original function.

```c
char buffer[] = {'H', 'e', 'l', 'l', 'o'}; // Without '\0' at the end
size_t len = strlen(buffer); // Undefined behavior
```

---

## `ft_strlcpy`

> Mimics `strlcpy` function:  
Copies a string from `src` to `dst`, ensuring the destination buffer doesn't overflow (`dstsize - 1`)  
and guaranteeing null-termination if `dstsize` is not 0.

#### Original Function:
| **Library**    | `<bsd/string.h>`                                                                                   |
|:---------------|:--------------------------------------------------------------------------------------------------|
| **Signature**  | `size_t strlcpy(char *dst, const char *src, size_t dstsize);`                                      |
| **Parameters** | `dst`: Pointer to the destination buffer.                                                          |
|                | `src`: Pointer to the source string to be copied.                                                  |
|                | `dstsize`: Size of the destination buffer.                                                         |
| **Return**     | The total length of the source string (`src`).                                                     |
| **Manual**     | [strlcpy(3) - Linux Manual](https://linux.die.net/man/3/strlcpy)                                   |

#### **Usage Example:**

```c
char dest[5];
size_t len = strlcpy(dest, "Hello", sizeof(dest)); // Copies "Hell", len returns 5
```

#### **Specifics:**

> Ensures null-termination if `dstsize > 0`.

```c
char dest[5];
size_t len = strlcpy(dest, "Hello", sizeof(dest)); // Copies "Hell\0"
```

---

## `ft_strlcat`

> Mimics `strlcat` function:  
Appends a string from `src` to `dst`, ensuring the destination buffer doesn't overflow (`dstsize - 1`)  
and guaranteeing null-termination if `dstsize` is not 0.

#### Original Function:
| **Library**    | `<bsd/string.h>`                                                                                   |
|:---------------|:--------------------------------------------------------------------------------------------------|
| **Signature**  | `size_t strlcat(char *dst, const char *src, size_t dstsize);`                                      |
| **Parameters** | `dst`: Pointer to the destination string buffer.                                                   |
|                | `src`: Pointer to the source string.                                                              |
|                | `dstsize`: Size of the destination buffer.                                                         |
| **Return**     | The total length of the string it tried to create.                                                 |
| **Manual**     | [strlcat(3) - Linux Manual](https://linux.die.net/man/3/strlcat)                                   |

#### **Usage Example:**

```c
char dest[10] = "Hi";
size_t len = strlcat(dest, " there", sizeof(dest)); // Returns total length attempted (8)
```

#### **Specifics:**

> Ensures null-termination if `dstsize > 0` and destination space is available.

```c
char dest[5];
size_t len = strlcat(dest, "Hello", sizeof(dest)); // Copies "Hel\0"
```

---

## `ft_strchr`

> Mimics `strchr` function:  
Locates the first occurrence of a character `c` in the string `s`.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `char *strchr(const char *s, int c);`                                                             |
| **Parameters** | `s`: Pointer to the string to search.                                                             |
|                | `c`: Character to locate.                                                                         |
| **Return**     | A pointer to the first occurrence of `c`, or `NULL` if not found.                                 |
| **Manual**     | [strchr(3) - Linux Manual](https://man7.org/linux/man-pages/man3/strchr.3.html)                   |

#### **Usage Example:**

```c
char *ptr = strchr("Hello", 'e'); // Returns pointer to 'e'
```

#### **Specifics:**

> If `c` is `'\0'`, `strchr` returns a pointer to the null terminator.

```c
char *ptr = strchr("Hello", '\0'); // Returns pointer to null terminator
```

---

## `ft_strrchr`

> Mimics `strrchr` function:  
Locates the last occurrence of a character `c` in the string `s`.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `char *strrchr(const char *s, int c);`                                                            |
| **Parameters** | `s`: Pointer to the string to search.                                                             |
|                | `c`: Character to locate.                                                                         |
| **Return**     | A pointer to the last occurrence of `c`, or `NULL` if not found.                                  |
| **Manual**     | [strrchr(3) - Linux Manual](https://man7.org/linux/man-pages/man3/strrchr.3p.html)                 |

#### **Usage Example:**

```c
char *ptr = strrchr("Hello", 'l'); // Returns pointer to the second 'l'
```

#### **Specifics:**

> If `c` is `'\0'`, `strrchr` returns a pointer to the null terminator.

```c
char *ptr = strrchr("Hello", '\0'); // Returns pointer to null terminator
```

---

## `ft_strncmp`

> Mimics `strncmp` function:  
Compares up to `n` characters of two strings.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int strncmp(const char *s1, const char *s2, size_t n);`                                          |
| **Parameters** | `s1`: First string.                                                                               |
|                | `s2`: Second string.                                                                              |
|                | `n`: Maximum number of characters to compare.                                                     |
| **Return**     | Integer less than, equal to, or greater than zero if `s1` is less than, equal to, or greater than `s2`. |
| **Manual**     | [strncmp(3) - Linux Manual](https://man7.org/linux/man-pages/man3/strncmp.3p.html)                 |

#### **Usage Example:**

```c
int result = strncmp("Hello", "World", 3); // Compares first 3 chars, returns negative
```

---

## `ft_strnstr`

> Mimics `strnstr` function:  
Locates the first occurrence of the substring `little` in `big`, searching only the first `len` characters.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `strnstr(const char *big, const char *little, size_t len);`                            |
| **Parameters** | `big`: String to search in.                                                                  |
|                | `little`: Substring to find.                                                                      |
|                | `len`: Maximum number of characters to search.                                                    |
| **Return**     | Pointer to the beginning of the located substring, or `NULL` if not found.                        |
| **Manual**     | [strnstr(3) - FreeBSD Manual](https://www.freebsd.org/cgi/man.cgi?query=strnstr)                  |

#### **Usage Example:**

```c
char *result = strnstr("Hello, World!", "World", 12); // Finds "World"
```

---

## `ft_strdup`

> Mimics `strdup` function:  
Allocates memory and duplicates the given string `s`.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `char *strdup(const char *s);`                                                                    |
| **Parameters** | `s`: String to duplicate.                                                                         |
| **Return**     | Pointer to the newly allocated string, or `NULL` if memory allocation fails.                      |
| **Manual**     | [strdup(3) - Linux Manual](https://man7.org/linux/man-pages/man3/strdup.3.html)                   |

#### **Usage Example:**

```c
char *copy = strdup("Hello"); // Allocates and copies "Hello" into a new string
```

#### **Specifics:**

> `strdup` allocates memory, so the returned string must be freed after use.

```c
char *copy = strdup("Hello");
free(copy); // Freeing the allocated memory
```
---

Additional

## `ft_substr`

> Description:  
Creates a new string by extracting a substring from the string `s`, starting at the index `start` and up to `len` characters long. 

| **Signature**        | `char *ft_substr(char const *s, unsigned int start, size_t len);`                                |
|:---------------------|:-------------------------------------------------------------------------------------------------|
| **Parameters**       | `s`: The string from which to create the substring.                                              |
|                      | `start`: The starting index of the substring in the string `s`.                                  |
|                      | `len`: The maximum length of the substring.                                                      |
| **Return value**     | A newly allocated substring, or `NULL` if the allocation fails.                                  |
| **Equivalent**       | The C++ `std::string` class has the `.substr()` method to extract substrings.                    |

#### **Usage Example:**:

```c
char *str = "Hello, World!";
char *substr = ft_substr(str, 7, 5); // Creates a new string "World"
```

#### **Specifics:**

> `ft_substr` allocates memory, so the returned string must be freed after use.

```c
char *copy = ft_substr("Hello");
free(copy); // Freeing the allocated memory
```


---

## `ft_strjoin`

> Description:  
Creates a new string, which is the result of the concatenation of `s1` and `s2`.

| **Signature**        | `char *ft_strjoin(char const *s1, char const *s2);`                                             |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s1`: The prefix string.                                                                         |
|                      | `s2`: The suffix string.                                                                         |
| **Return value**     | A newly allocated string resulting from the concatenation of `s1` and `s2`, or `NULL` if the allocation fails. |
| **Equivalent**       | The C++ `std::string` class concatenation using the `+` operator.                  |

#### **Usage Example:**

```c
char *s1 = "Hello";
char *s2 = " World!";
char *joined = ft_strjoin(s1, s2); // Creates a new string "Hello World!"
```

#### **Specifics:**

> `ft_strjoin` allocates memory, so the returned string must be freed after use.

```c
char *joined = ft_strjoin("Hello", " World!");
free(joined); // Freeing the allocated memory
```

---


## `ft_strtrim`

> Description:  
Creates a new string, which is a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string.

| **Signature**        | `char *ft_strtrim(char const *s1, char const *set);`                                            |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s1`: The string to be trimmed.                                                                 |
|                      | `set`: The reference set of characters to trim.                                                 |
| **Return value**     | A newly allocated trimmed string, or `NULL` if the allocation fails.                             |
| **Equivalent**       | None.                                                                                           |

#### **Usage Example:**

```c
char *s1 = "  Hello, World!  ";
char *trimmed = ft_strtrim(s1, " "); // Creates a new string "Hello, World!"
```

#### **Specifics:**

> `ft_strtrim` allocates memory, so the returned string must be freed after use.

```c
char *trimmed = ft_strtrim("  Hello  ", " ");
free(trimmed); // Freeing the allocated memory
```

---

## `ft_split`

> Description:  
Creates an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array ends with a `NULL` pointer.

| **Signature**        | `char **ft_split(char const *s, char c);`                                                      |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s`: The string to be split.                                                                    |
|                      | `c`: The delimiter character.                                                                   |
| **Return value**     | A newly allocated array of strings resulting from the split, or `NULL` if the allocation fails.  |
| **Equivalent**       | None.                                                                                           |

#### **Usage Example:**

```c
char **result = ft_split("Hello World Hello", ' '); // Creates new strings: "Hello" "World" "Hello"
```

#### **Specifics:**

> `ft_split` allocates memory for each substring and the array itself. All memory must be freed after use.

```c
char **result = ft_split("Hello World", ' ');
for (int i = 0; result[i] != NULL; i++)
    free(result[i]); // Free each substring
free(result); // Free the array
```
---

## `ft_strmapi`

> Description:  
Applies the function `f` to each character of the string `s` to create a new string, resulting from successive applications of `f`.

| **Signature**        | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`                               |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s`: The string on which to iterate.                                                             |
|                      | `f`: The function to apply to each character.                                                    |
| **Return value**     | A newly allocated string, or `NULL` if the allocation fails.                                      |
| **Equivalent**       | None.                                                                                           |

#### **Usage Example:**

```c
char *result = ft_strmapi("hello", to_uppercase); // Creates a new string "HELLO"
```

#### **Specifics:**

> `ft_strmapi` allocates memory for the new string, so the returned string must be freed after use.

```c
char *result = ft_strmapi("abc", to_uppercase);
free(result); // Freeing the allocated memory
```

---

## `ft_striteri`

> Description:  
Applies the function `f` to each character of the string `s`, passing its index as the first argument. Each character is passed by reference to `f` to be modified if necessary.

| **Signature**        | `void ft_striteri(char *s, void (*f)(unsigned int, char *));`                                    |
|:---------------------|:------------------------------------------------------------------------------------------------|
| **Parameters**       | `s`: The string on which to iterate.                                                             |
|                      | `f`: The function to apply to each character, taking its index and the character as arguments.   |
| **Return value**     | None.                                                                                            |
| **Equivalent**       | None.                                                                                           |

#### **Usage Example:**

```c
char str[] = "hello";
ft_striteri(str, to_uppercase); // Transform passed string to "HELLO"
```

#### **Specifics:**

> Since `ft_striteri` modifies the string `s` in-place, no need to free any memory after use.

---
