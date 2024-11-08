#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int		i;
	int		count;
	int		write_result;

	i = 0;
	count = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		write_result = write(1, &str[i], 1);
		if (write_result == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}

static int	ft_count_digits(int n)
{
	int	count;

    count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char *ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nbr;

	nbr = n;
	size = ft_count_digits(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

int	ft_print_d(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_print_s("-2147483648\n"));

	str = ft_itoa(n);
	if (!str)
		return (0);

	len = ft_print_s(str);
	len += ft_print_s("\n");
	free(str);
	return (len);
}

static size_t p_digits(unsigned long long n)
{
    size_t digits;

	digits = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 16;
        digits++;
    }
    return (digits);
}

void print_ptr_rec(unsigned long long ptr)
{
    char hex_digit;

    if (ptr >= 16)
        print_ptr_rec(ptr / 16);
    hex_digit = "0123456789abcdef"[ptr % 16];
    ft_print_c(hex_digit);
}

int ft_print_p(unsigned long long ptr)
{
    int len = 0;

    if (ptr == 0)
        return (write(1, "(nil)", 5));
    len = write(1, "0x", 2);
    print_ptr_rec(ptr);
    len += p_digits(ptr);
    return (len);
}

static size_t u_digits(unsigned int n)
{
    size_t digits;

	digits = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 10;
        digits++;
    }
    return (digits);
}

char *ft_utoa(unsigned int n)
{
    char *str;
    int num_len;

    num_len = u_digits(n);
    str = (char *)malloc((num_len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[num_len] = '\0';
    while (num_len > 0)
    {
        str[num_len - 1] = (n % 10) + '0';
        n = n / 10;
        num_len--;
    }
    return (str);
}

int ft_print_u(unsigned int n)
{
    int num_len;
    char *str;

    if (n == 0)
        return write(1, "0", 1);
    str = ft_utoa(n);
    if (!str)
        return (-1);
    num_len = 0;
    while (str[num_len] != '\0')
        num_len++;
    write(1, str, num_len);
    free(str);
    return (num_len);
}

void print_hex_rec(unsigned int n, char format)
{
    char hex_digit;

    if (n >= 16)
        print_hex_rec(n / 16, format);
    hex_digit = "0123456789abcdef"[n % 16];
    if (format == 'X' && hex_digit >= 'a' && hex_digit <= 'f')
        hex_digit -= 32;
    ft_print_c(hex_digit);
}

int ft_print_x(unsigned int n, char format)
{
    int count;

    if (n == 0)
        return ft_print_c('0');

    count = 0;
    print_hex_rec(n, format);
    while (n > 0)
    {
        n /= 16;
        count++;
    }

    return (count);
}

int format_printf(va_list args, const char format)
{
    if (format == 'c')
        return (ft_print_c(va_arg(args, int)));
    else if (format == 's')
        return (ft_print_s(va_arg(args, char *)));
    else if (format == 'p')
        return (ft_print_p(va_arg(args, unsigned long long)));
    else if (format == 'd' || format == 'i')
        return (ft_print_d(va_arg(args, int)));
    else if (format == 'u')
        return (ft_print_u(va_arg(args, unsigned int)));
    else if (format == 'x' || format == 'X')
        return (ft_print_x(va_arg(args, unsigned int), format));
    else if (format == '%')
        return (ft_print_c('%'));
    return (0);
}

int handle_format(va_list args, const char *str, size_t *i)
{
    int len = 0;
    
    if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' ||
        str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' ||
        str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
    {
        len = format_printf(args, str[*i]);
    }
    else
    {
        ft_print_c('%');
        ft_print_c(str[*i]);
        len = 2;
    }
    (*i)++;
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    size_t i = 0;
    int len = 0;

    if (!format)
        return (-1);

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i])
                len += handle_format(args, format, &i);
        }
        else
        {
            len += ft_print_c(format[i]);
            i++;
        }
    }
    va_end(args);
    return (len);
}

#include <stdio.h>



/*
int	main(void)
{
	int	num;

	int ret1, ret2;
	// For character
	ret1 = ft_printf("Character: %c\n", 'A');
	ret2 = printf("Character: %c\n", 'A');
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For string
	ret1 = ft_printf("String: %s\n", "Hello, World!");
	ret2 = printf("String: %s\n", "Hello, World!");
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For pointer
	num = 10;
	ret1 = ft_printf("Pointer: %p\n", &num);
	ret2 = printf("Pointer: %p\n", &num);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For decimal (base 10)
	ret1 = ft_printf("Decimal: %d\n", 10000);
	ret2 = printf("Decimal: %d\n", 10000);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For integer
	ret1 = ft_printf("Integer: %i\n", -12345);
	ret2 = printf("Integer: %i\n", -12345);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For unsigned
	ret1 = ft_printf("Unsigned: %u\n", 12345);
	ret2 = printf("Unsigned: %u\n", 12345);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For hexadecimal (lowercase)
	ret1 = ft_printf("Hexadecimal (lowercase): %x\n", -1);
	ret2 = printf("Hexadecimal (lowercase): %x\n", -1);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For hexadecimal (uppercase)
	ret1 = ft_printf("Hexadecimal (uppercase): %X\n", 0x123abc);
	ret2 = printf("Hexadecimal (uppercase): %X\n", 0x123abc);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
	// For percent
	ret1 = ft_printf("Percent: %%\n");
	ret2 = printf("Percent: %%\n");
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	printf("-----------------------\n");
 }
*/

/*
sh-5.2$ cc -Wall -Werror -Wextra -g test_all.c -o test_all
sh-5.2$ valgrind ./test_all
==1134== Memcheck, a memory error detector
==1134== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==1134== Using Valgrind-3.23.0 and LibVEX; rerun with -h for copyright info
==1134== Command: ./test_all
==1134== 
Character: A
Character: A
ft_printf returned: 13, printf returned: 13
-----------------------
String: Hello, World!
String: Hello, World!
ft_printf returned: 22, printf returned: 22
-----------------------
Pointer: 0x1ffefffb0c
Pointer: 0x1ffefffb0c
ft_printf returned: 22, printf returned: 22
-----------------------
Decimal: 10000

Decimal: 10000
ft_printf returned: 16, printf returned: 15
-----------------------
Integer: -12345

Integer: -12345
ft_printf returned: 17, printf returned: 16
-----------------------
Unsigned: 12345
Unsigned: 12345
ft_printf returned: 16, printf returned: 16
-----------------------
Hexadecimal (lowercase): ffffffff
Hexadecimal (lowercase): ffffffff
ft_printf returned: 34, printf returned: 34
-----------------------
Hexadecimal (uppercase): 123ABC
Hexadecimal (uppercase): 123ABC
ft_printf returned: 32, printf returned: 32
-----------------------
Percent: %
Percent: %
ft_printf returned: 11, printf returned: 11
-----------------------
==1134== 
==1134== HEAP SUMMARY:
==1134==     in use at exit: 0 bytes in 0 blocks
==1134==   total heap usage: 4 allocs, 4 frees, 1,043 bytes allocated
==1134== 
==1134== All heap blocks were freed -- no leaks are possible
==1134== 
==1134== For lists of detected and suppressed errors, rerun with: -s
==1134== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/