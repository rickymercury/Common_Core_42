#include "ft_printf.h"

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

void	negative(int *number, int *count)
{
	if (*number < 0)
	{
		write(1, "-", 1);
		*number = -*number;
		(*count)++;
	}
}

int	ft_print_d(int n)
{
	int	count;
	int	digits[12];
	int	i;

	count = 0;
	if (n == -2147483648)
		return (ft_print_s("-2147483648"));
	negative(&n, &count);
	if (n == 0)
		return (ft_print_c('0'));
	i = 0;
	while (n != 0)
	{
		digits[i++] = n % 10;
		n = n / 10;
		count++;
	}
	i--;
	while (i >= 0)
		ft_print_c(digits[i--] + '0');
	return (count);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_lowercase(char a)
{
	if (a >= 'a' && a <= 'f')
		return (1);
	return (0);
}

static void	add_hex(unsigned int x)
{
	char	*hex;
	int		tmp;

	hex = "0123456789abcdef";
	if (!ft_isdigit(hex[x % 16]) && is_lowercase(hex[x % 16]))
	{
		tmp = hex[x % 16] - 32;
		write(1, &tmp, 1);
	}
	else
		write(1, &hex[x % 16], 1);
}

int	ft_print_x(unsigned int x, int upper)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (x >= 16)
		count += ft_print_x(x / 16, upper);
	if (upper)
		add_hex(x);
	else
		write(1, &hex[x % 16], 1);
	count++;
	return (count);
}
void convert_to_hex(uintptr_t int_to_convert, char *result, int *i)
{
    unsigned int remainder;
    char *hex = "0123456789ABCDEF";

    while (int_to_convert != 0)
    {
        remainder = int_to_convert % 16;
        result[(*i)--] = hex[remainder];
        int_to_convert /= 16;
    }
}

int convert_pointer(uintptr_t int_to_convert)
{
    int i;
    int counter;
    char result[17];

    i = 15;
    counter = 0;
    result[i--] = '\0';
    
    if (int_to_convert == 0)
    {
        result[i] = '0';
        counter += ft_print_c(result[i]);
    }
    else
        convert_to_hex(int_to_convert, result, &i);
    while (result[++i] != '\0')
        counter += ft_print_c(result[i]);
    return counter;
}

int	ft_print_p(uintptr_t ptr)
{
	if (!ptr)
		return (ft_print_s("(nil)"));
	ft_print_s("0x");
	return (2 + convert_pointer(ptr));
}

int	ft_print_s(const char *str)
{
	int		i;
	int		count;
	const char	*null_str;

	count = 0;
	if (!str)
	{
		null_str = "(null)";
		while (*null_str)
		{
			count += ft_print_c(*null_str);
			null_str++;
		}
		return (count);
	}
	i = 0;
	while (str[i])
	{
		count += ft_print_c(str[i]);
		i++;
	}
	return (count);
}

int count_digits(long nbr)
{
    int count;

    count = 0;
    if (nbr == 0)
        return (1);
    while (nbr > 0)
    {
        nbr /= 10;
		count++;
    }
    return (count);
}

int ft_print_u(unsigned int n)
{
    unsigned long nbr;
    int digit_count;

    nbr = n;
    if (nbr == 0)
    {
        ft_print_c('0');
        return (1);
    }
    digit_count = count_digits(nbr);
    if (nbr >= 10)
        ft_print_u(nbr / 10);
    ft_print_c(nbr % 10 + '0');
    return (digit_count);
}

int format_printf(va_list args, const char format)
{
    if (format == 'c')
        return (ft_print_c(va_arg(args, int)));
    else if (format == 's')
        return (ft_print_s(va_arg(args, const char *)));
    else if (format == 'p')
        return (ft_print_p(va_arg(args, uintptr_t)));
    else if (format == 'd' || format == 'i')
        return (ft_print_d(va_arg(args, int)));
    else if (format == 'u')
        return (ft_print_u(va_arg(args, unsigned int)));
     else if (format == 'x')
        return (ft_print_x(va_arg(args, unsigned int), 0));
    else if (format == 'X')
        return (ft_print_x(va_arg(args, unsigned int), 1));
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

