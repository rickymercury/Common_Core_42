<h1 align="center">Memory</h1>

<p align="center">
<a href="#strings">Strings</a>• 
<a href="#utils">Utils</a>•
<a href="#strings"> Top ⬆️ </a>
</p>

## `ft_memset`

> Mimics `memset` function:  
Fills a block of memory with a specified value.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `void *memset(void *s, int c, size_t n);`                                                         |
| **Parameters** | `s`: Pointer to the memory block.                                                                 |
|                | `c`: Value to set (converted to unsigned char).                                                   |
|                | `n`: Number of bytes to set.                                                                      |
| **Return**     | Pointer to the memory block `s`.                                                                  |
| **Manual**     | [memset(3) - Linux Manual](https://man7.org/linux/man-pages/man3/memset.3.html)                   |

#### **Usage Example:**

```c
char buffer[10];
memset(buffer, 0, 10); // Fills buffer with zeros
```

---

## `ft_bzero`

> Mimics `bzero` function:  
Zeroes out a block of memory.

#### Original Function:
| **Library**    | `<strings.h>`                                                                                     |
|:---------------|:--------------------------------------------------------------------------------------------------|
| **Signature**  | `void bzero(void *s, size_t n);`                                                                  |
| **Parameters** | `s`: Pointer to the memory block.                                                                 |
|                | `n`: Number of bytes to set to zero.                                                              |
| **Return**     | None.                                                                                             |
| **Manual**     | [bzero(3) - Linux Manual](https://man7.org/linux/man-pages/man3/bzero.3.html)                     |

#### **Usage Example:**

```c
char buffer[10];
bzero(buffer, 10); // Sets all bytes in buffer to zero
```

#### **Specifics:**
>  `bzero` is considered deprecated in favor of `memset`, which achieves the same result.

```c
Copiar código
bzero(buffer, 10);  // Equivalent to memset(buffer, 0, 10);
```

---

## `ft_memcpy`

> Mimics `memcpy` function:  
Copies `n` bytes from source to destination.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `void *memcpy(void *dest, const void *src, size_t n);`                                            |
| **Parameters** | `dest`: Destination memory block.                                                                 |
|                | `src`: Source memory block.                                                                       |
|                | `n`: Number of bytes to copy.                                                                     |
| **Return**     | Pointer to the destination memory block `dest`.                                                   |
| **Manual**     | [memcpy(3) - Linux Manual](https://man7.org/linux/man-pages/man3/memcpy.3.html)                   |

#### **Usage Example:**

```c
char src[10] = "Hello";
char dest[10];
memcpy(dest, src, 5); // Copies "Hello" to dest
```

#### **Specifics:**

> `memcpy` has undefined behavior if source and destination overlap. Use `memmove` instead for overlapping memory.

```c
memcpy(src + 1, src, 5); // Undefined behavior
```

---

## `ft_memmove`

> Mimics `memmove` function:  
Safely copies `n` bytes from source to destination, even if memory regions overlap.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `void *memmove(void *dest, const void *src, size_t n);`                                           |
| **Parameters** | `dest`: Destination memory block.                                                                 |
|                | `src`: Source memory block.                                                                       |
|                | `n`: Number of bytes to copy.                                                                     |
| **Return**     | Pointer to the destination memory block `dest`.                                                   |
| **Manual**     | [memmove(3) - Linux Manual](https://man7.org/linux/man-pages/man3/memmove.3.html)                 |

#### **Usage Example:**

```c
char src[10] = "Hello";
memmove(src + 1, src, 5); // Safely copies "Hello" to "HHello"
```

---

## `ft_memchr`

> Mimics `memchr` function:  
Searches for the first occurrence of a byte in a memory block.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `void *memchr(const void *s, int c, size_t n);`                                                   |
| **Parameters** | `s`: Pointer to the memory block.                                                                 |
|                | `c`: Byte to search for (converted to unsigned char).                                             |
|                | `n`: Number of bytes to search.                                                                   |
| **Return**     | Pointer to the first occurrence of the byte `c`, or `NULL` if not found.                          |
| **Manual**     | [memchr(3) - Linux Manual](https://man7.org/linux/man-pages/man3/memchr.3.html)                   |

#### **Usage Example:**

```c
char data[] = "Hello, World!";
char *ptr = memchr(data, 'W', sizeof(data)); // Returns pointer to 'W'
```

---

## `ft_memcmp`

> Mimics `memcmp` function:  
Compares the first `n` bytes of two memory blocks.

#### Original Function:
| **Library**    | `<string.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `int memcmp(const void *s1, const void *s2, size_t n);`                                           |
| **Parameters** | `s1`: First memory block.                                                                         |
|                | `s2`: Second memory block.                                                                        |
|                | `n`: Number of bytes to compare.                                                                  |
| **Return**     | Integer less than, equal to, or greater than zero if `s1` is less than, equal to, or greater than `s2`. |
| **Manual**     | [memcmp(3) - Linux Manual](https://man7.org/linux/man-pages/man3/memcmp.3.html)                   |

#### **Usage Example:**

```c
int result = memcmp("ABC", "ABD", 3); // Returns a negative value
```

---

## `ft_calloc`

> Mimics `calloc` function:  
Allocates memory for an array of `nmemb` elements of `size` bytes each and initializes the allocated memory to zero.

#### Original Function:
| **Library**    | `<stdlib.h>`                                                                                     |
|:---------------|:-------------------------------------------------------------------------------------------------|
| **Signature**  | `void *calloc(size_t nmemb, size_t size);`                                                        |
| **Parameters** | `nmemb`: Number of elements to allocate.                                                                      |
|                | `size`: Size of each element.                                                                     |
| **Return**     | Pointer to the allocated memory, or `NULL` if the allocation fails.                               |
| **Manual**     | [calloc(3) - Linux Manual](https://man7.org/linux/man-pages/man3/calloc.3.html)                   |

#### **Usage Example:**

```c
int *arr = calloc(5, sizeof(int)); // Allocates and zeroes memory for an array of 5 integers
```

#### **Specifics:**

> If `nmemb` or `size` is 0, `calloc` returns a unique pointer that can be passed to `free()`.

```c
int *arr = calloc(0, sizeof(int)); // Returns a unique pointer, safe to pass to free()
```

> If the multiplication of `nmemb` and `size` results in an integer overflow, `calloc` returns `NULL`.

```c
size_t nmemb = SIZE_MAX;
size_t size = 2;
void *ptr = calloc(nmemb, size); // Returns NULL due to integer overflow
```

---
