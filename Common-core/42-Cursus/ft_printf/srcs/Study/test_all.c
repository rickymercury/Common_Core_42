#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_numlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nbr;

	nbr = n;
	size = ft_numlen(n);
	str = (char *) malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	size--;
	while (nbr > 0 && size >= 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (str);
}

int	ft_print_d(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_print_s(str);
	free(str);
	return (len);
}

static int	ft_count_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		count++;
		ptr = ptr / 16;
	}
	return (count);
}

int	ft_recursive_print_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_recursive_print_ptr(ptr / 16);
		ft_recursive_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_print_c(ptr + 48);
		else
			ft_print_c(ptr - 10 + 'a');
	}
	return (ft_count_ptr(ptr));
}

int	ft_print_p(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len = write (1, "0x", 2);
	len += ft_recursive_print_ptr(ptr);
	return (len);
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

int	ft_len_num(unsigned int num)
{
	int	len = 0;

	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_len_num(n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (len > 0)
	{
		num[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_u(unsigned int n)
{
	int		len;
	char	*num;

	if (n == 0)
		return (write(1, "0", 1));
	num = ft_utoa(n);
	if (!num)
		return (-1);
	len = 0;
	while (num[len] != '\0')
		len++;
	write(1, num, len);
	free(num);
	return (len);
}

int ft_hex_len(unsigned int num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        num = num / 16;
        len++;
    }
    return (len);
}

void ft_recursive_print_hex(unsigned int num, const char hex_format)
{
    if (num >= 16)
    {
        ft_recursive_print_hex(num / 16, hex_format);
        ft_recursive_print_hex(num % 16, hex_format);
    }
    else
    {
        if (num <= 9)
            ft_print_c((num + '0'));
        else
        {
            if (hex_format == 'x')
                ft_print_c((num - 10 + 'a'));
            if (hex_format == 'X')
                ft_print_c((num - 10 + 'A'));
        }
    }
}

int ft_print_x(unsigned int num, const char hex_format)
{
    if (num == 0)
        return (write(1, "0", 1));
    else
        ft_recursive_print_hex(num, hex_format);
    return (ft_hex_len(num));
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_arg(va_list args, const char format)
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

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			length;

	if (!format)
		return (-1);
	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_printf_arg(args, format[i + 1]);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}


#include <stdio.h>

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