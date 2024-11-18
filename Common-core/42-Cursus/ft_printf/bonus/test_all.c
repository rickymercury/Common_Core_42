#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t ft_strlen(const char *str) 
{
    size_t len = 0;
    while (str[len] != '\0') 
        len++;
    return len;
}

int	ft_putstr(char *str)
{
	int	len;

    len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(str + i));  // (str + i) = &p[i]
		i++;
	}
	return (NULL);
}

int	ft_print_c(t_flags *flags, int c)
{
	int	count;

	count = 0;
	if (flags -> align_left == TRUE)
	{
		count += ft_putchar(c);
		flags -> width -= 1;
		while (flags -> width > 0)
		{
			count += ft_putchar(' ');
			flags -> width -= 1;
		}
		return (count);
	}
	while (flags -> width > 1)
	{
		count += ft_putchar(' ');
		flags -> width -= 1;
	}
	count += ft_putchar(c);
	return (count);
}

int	ft_print_u(size_t number)
{
	int	count;

	count = 0;
	if (number < 10)
	{
		count++;
		ft_putchar(number + 48);
		return (count);
	}
	count += ft_print_u(number / 10);
	count += ft_print_u(number % 10);
	return (count);
}

int ft_putnbr(int number) 
{
    char    c;
    int count;

    count = 0;
    if (number == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (number < 0)
    {
        count += write(1, "-", 1);
        number = -number;
    }
    if (number >= 10) 
        count += ft_putnbr(number / 10);
    c = (number % 10) + '0';
    count += write(1, &c, 1);
    return (count);
} 

int	print_d_zeros(long number, int precision)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number);
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	while (count < precision - len)
		count += ft_putchar('0');
	count += ft_print_u(number);
	return (count);
}

int	numlen(long number)
{
	int	len;

	len = 1;
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		len++;
		number /= 10;
	}
	return (len);
}

int	print_d_width_v2(long number, int width, char padding, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number + 1);
	if (padding == '0')
	{
		ft_putchar(sign);
		while (count < width - len)
			count += ft_putchar('0');
		return (count + ft_putnbr(number) + 1);
	}
	while (count < width - len)
		count += ft_putchar(' ');
	ft_putchar(sign);
	return (count + ft_putnbr(number) + 1);
}

int	print_d_width_precision_v2(long number, int width, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number);
	if (precision > len)
		len = precision;
	while (count < width - len - 1)
		count += ft_putchar(' ');
	return (count + print_d_precision(number, precision, sign));
}

int	print_d_left(long number, int width, int precision, char sign)
{
	int	count;

	count = 0;
	if (number == 0 && width > 0)
	{
		if (precision != 0)
			count += ft_putchar('0');
		while (count < precision)
			count += ft_putchar('0');
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	count += print_d_precision(number, precision, sign);
	while (count < width)
		count += ft_putchar(' ');
	return (count);
}

int	print_d_precision(long number, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(number);
	if (number == 0 && precision == 0)
		return (0);
	if (number < 0)
		return (print_d_zeros(number, precision + 1));
	if (sign == '+' || sign == ' ')
		count += ft_putchar(sign);
	while (count < precision - len)
		count += ft_putchar('0');
	return (count + ft_print_u(number));
}

int	print_d_width(long number, int width, char padding, char sign)
{
	int	len;
	int	count;

	count = 0;
	if (number < 0)
	{
		len = numlen(number);
		if (padding == '0')
			return (print_d_zeros(number, width));
		while (count < width - len - 1)
			count += ft_putchar(' ');
		return (count + ft_putnbr(number));
	}
	if (sign == '+')
		return (print_d_width_v2(number, width, padding, sign));
	len = numlen(number);
	while (count < width - len)
		count += ft_putchar(padding);
	return (count + ft_print_u(number));
}

int	print_d_width_precision(long number, int width, int precision, char sign)
{
	int	count;
	int	len;

	count = 0;
	if (number < 0)
	{
		len = numlen(number);
		if (precision > len)
			len = precision;
		while (count < width - len - 1)
			count += ft_putchar(' ');
		return (count += print_d_precision(number, precision, sign));
	}
	if (sign == '+' || sign == ' ')
		return (print_d_width_precision_v2(number, width, precision, sign));
	len = numlen(number);
	if (number == 0)
		len = 0;
	if (precision > len)
		len = precision;
	while (count < width - len)
		count += ft_putchar(' ');
	return (count + print_d_precision(number, precision, sign));
}

int	ft_print_d(t_flags *flags, long number)
{
	char	sign;
	char	padding;

	sign = '-';
	padding = ' ';
	if (flags -> space)
		sign = ' ';
	if (flags -> plus)
		sign = '+';
	if (flags -> zero)
		padding = '0';
	if (flags -> align_left)
		return (print_d_left(number, flags->width,
				flags->precision - 1, sign));
	if (flags -> width > 0 && flags -> precision > 0)
		return (print_d_width_precision(number, flags->width, flags->precision - 1, sign));
	if (flags -> width)
		return (print_d_width(number, flags->width, padding, sign));
	if (flags -> precision)
		return (print_d_width_precision(number, flags->width, flags->precision - 1, sign));
	if (number < 0)
		return (ft_putnbr(number));
	if (sign == '+' || sign == ' ')
		return (ft_putchar(sign) + ft_print_u(number));
	return (ft_print_u(number));
}

int	ptr_len(size_t number)
{
	int	i;

	i = 0;
	if (number < 16)
		return (i += 1);
	i += ptr_len(number / 16);
	i += ptr_len(number % 16);
	return (i);
}

int	print_ptr_address(size_t number, char ptr)
{
	int	printed;

	printed = 0;
	if (number < 16)
	{
		if (ptr == 'x')
			return (printed += ft_putchar("0123456789abcdef"[number]));
		else if (ptr == 'X')
			return (printed += ft_putchar("0123456789ABCDEF"[number]));
		return (printed);
	}
	printed += print_ptr_address(number / 16, ptr);
	printed += print_ptr_address(number % 16, ptr);
	return (printed);
}

int	print_p_spaces(int width, int align_left, size_t number)
{
	int	string_len;

	string_len = ptr_len(number) + 2;
	if (width <= string_len)
	{
		ft_putstr("0x");
		print_ptr_address(number, 'x');
		return (string_len);
	}
	if (align_left)
	{
		ft_putstr("0x");
		print_ptr_address(number, 'x');
		while (width > string_len)
			string_len += ft_putchar(' ');
		return (string_len);
	}
	while (string_len < width)
		string_len += ft_putchar(' ');
	ft_putstr("0x");
	print_ptr_address(number, 'x');
	return (string_len);
}

int	ft_print_p(t_flags *flags, size_t number)
{
	int	string_len;

	string_len = 0;
	if (number == 0)
	{
		string_len = 5;
		if (flags -> width <= 5)
			return (ft_putstr("(nil)"));
		if (flags -> align_left)
		{
			ft_putstr("(nil)");
			while (string_len < flags -> width)
				string_len += ft_putchar(' ');
			return (string_len);
		}
		while (flags -> width > string_len)
			string_len += ft_putchar(' ');
		ft_putstr("(nil)");
		return (string_len);
	}
	if (flags -> width > 0)
		return (print_p_spaces(flags -> width, flags -> align_left, number));
	string_len += ft_putstr("0x");
	string_len += print_ptr_address(number, 'x');
	return (string_len);
}

int	putstr_width_precision(int width, int precision, char *str, int align_left)
{
	int	string_len;
	int	count;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		if (precision < 6)
			precision = 0;
	}
	string_len = (int)ft_strlen(str);
	if (precision < string_len)
		string_len = precision;
	if (string_len >= width)
		return (putstr_precision(precision, str));
	if (align_left)
	{
		count += putstr_precision(precision, str);
		while (count < width)
			count += ft_putchar(' ');
		return (count);
	}
	while (count < width - string_len)
		count += ft_putchar(' ');
	return (count + putstr_precision(precision, str));
}

int	putstr_width(int width, char *str, int align_left)
{
	int		string_len;
	int		printed_len;

	if (str == NULL)
		str = "(null)";
	string_len = (int)ft_strlen(str);
	printed_len = 0;
	if (string_len >= width)
		return (ft_putstr(str));
	if (align_left == TRUE)
	{
		printed_len += ft_putstr(str);
		while (printed_len < width)
			printed_len += ft_putchar(' ');
		return (printed_len);
	}
	while (printed_len < width - string_len)
		printed_len += ft_putchar(' ');
	printed_len += ft_putstr(str);
	return (printed_len);
}

int	putstr_precision(int precision, char *str)
{
	int	total_printed;

	total_printed = 0;
	if (str == NULL)
	{
		str = "(null)";
		if (precision < 6)
			precision = 0;
	}
	while (str[total_printed] && total_printed < precision)
		total_printed += ft_putchar(str[total_printed]);
	return (total_printed);
}

int	ft_print_s(t_flags *flags, char *str)
{
    if (str == NULL)
    {
        str = "(null)";
    }
	if (flags -> width > 0 && flags -> precision)
		return (putstr_width_precision(flags->width,
				flags->precision - 1, str, flags->align_left));
	if (flags -> width > 0)
		return (putstr_width(flags -> width, str, flags -> align_left));
	if (flags -> precision > 0)
		return (putstr_precision(flags -> precision - 1, str));
	return (ft_putstr(str));
}

int	hex_len(size_t number)
{
	int	i;

	i = 0;
	if (number < 16)
		return (i += 1);
	i += hex_len(number / 16);
	i += hex_len(number % 16);
	return (i);
}

int	print_hex_adress(size_t number, char x)
{
	int	printed;

	printed = 0;
	if (number < 16)
	{
		if (x == 'x')
			return (printed += ft_putchar("0123456789abcdef"[number]));
		else if (x == 'X')
			return (printed += ft_putchar("0123456789ABCDEF"[number]));
		return (printed);
	}
	printed += print_ptr_address(number / 16, x);
	printed += print_ptr_address(number % 16, x);
	return (printed);
}

int	print_x_precision(int precision, long number, char x)
{
	int	count;

	if (number == 0 && precision == 0)
		return (0);
	count = hex_len(number);
	while (count < precision)
		count += ft_putchar('0');
	print_hex_adress(number, x);
	return (count);
}

int	print_x_left(t_flags *flags, long number, char x)
{
	int	count;

	count = 0;
	if (flags -> hash)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(x);
	}
	count += print_x_precision(flags -> precision - 1, number, x);
	while (count < flags -> width)
		count += ft_putchar(' ');
	return (count);
}

int	print_x_hash(t_flags *flags, long number, char x, char padding)
{
	int	count;
	int	len;

	count = 0;
	len = hex_len(number);
	if (flags -> precision - 1 - len)
		len = flags -> precision - 1;
	if (padding == 0)
	{
		if (number != 0)
			count += ft_putchar('0') + ft_putchar(x);
		while (count < flags -> width - len)
			count += ft_putchar(padding);
		count += print_x_precision(flags -> precision - 1, number, x);
		return (count);
	}
	while (count < flags -> width - 2 - len)
		count += ft_putchar(padding);
	if (number != 0)
		count += ft_putchar('0') + ft_putchar(x);
	count += print_x_precision(flags -> precision - 1, number, x);
	return (count);
}

int	print_x_width(t_flags *flags, long number, char x, char padding)
{
	int	count;
	int	len;

	count = 0;
	len = hex_len(number);
	if (flags -> precision - 1 > len)
		len = flags -> precision - 1;
	if (number == 0 && flags -> precision == 1)
		len = 0;
	while (count < flags -> width - len)
		count += ft_putchar(padding);
	count += print_x_precision(flags -> precision - 1, number, x);
	return (count);
}

int	ft_print_x(t_flags *flags, long number, char x)
{
	char	padding;
	int		len;

	padding = ' ';
	if (flags -> zero)
		padding = '0';
	if (flags -> width && flags -> precision)
		padding = ' ';
	if (flags -> align_left)
		return (print_x_left(flags, number, x));
	if (flags -> hash)
		return (print_x_hash(flags, number, x, padding));
	if (flags -> width)
		return (print_x_width(flags, number, x, padding));
	if (flags -> precision)
		return (print_x_precision(flags -> precision - 1, number, x));
	len = hex_len(number);
	print_hex_adress(number, x);
	return (len);
}

int	print_format(t_flags *flags, const char *type, int *i, va_list args)
{
	int	count;
    char *s;

	count = 0;
	if (type[*i] == 'c')
		count += ft_print_c(flags, va_arg(args, int));
	if (type[*i] == 's')
    {
        s = va_arg(args, char*);
        if (s == NULL)
            s = "(null)";
        count += ft_print_s(flags, s);
    }
	if (type[*i] == 'p')
		count += ft_print_p(flags, va_arg(args, size_t));
	if (type[*i] == 'd' || type[*i] == 'i')
		count += ft_print_d(flags, va_arg(args, int));
	if (type[*i] == 'u')
		count += ft_print_d(flags, va_arg(args, unsigned int));
	if (type[*i] == 'x' || type[*i] == 'X')
		count += ft_print_x(flags, va_arg(args, unsigned int), type[*i]);
	if (type[*i] == '%')
		count += ft_putchar('%');
	(*i)++;
	return (count);
}

void	parse_flags(t_flags *flags, const char *flag, int *i)
{
	while (flag[*i] == '-' || flag[*i] == '+'
		|| flag[*i] == ' ' || flag[*i] == '#')
	{
		if (flag[*i] == '-')
			flags -> align_left = TRUE;
		if (flag[*i] == '+')
			flags -> plus = TRUE;
		if (flag[*i] == ' ')
			flags -> space = TRUE;
		if (flag[*i] == '#')
			flags -> hash = TRUE;
		(*i)++;
	}
	if (flag[*i] == '0')
		flags -> zero = TRUE;
	if (ft_isdigit(flag[*i]) || flag[*i] == '.')
	{
		if (flag[*i] == '.')
			flags -> precision = ft_atoi(&flag[++*i]) + 1;
		else
			flags -> width = ft_atoi(&flag[*i]);
		while (ft_isdigit(flag[*i]))
			(*i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		count;

	if (!str || (str[0] == '%' && str[1] == '\0'))
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		ft_bzero(&flags, sizeof(t_flags));
		if (str[i] == '%')
		{
			i++;
			while (ft_memchr("-0.# +", str[i], 6) || ft_isdigit(str[i]))
				parse_flags(&flags, str, &i);
			count += print_format(&flags, str, &i, args);
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}


#include <stdio.h>
#include <limits.h>

int main(void)
{
	int output_OG;
	int output_FT;

/////////////////////////////////
//  	  NO SPECIFIERS		   //
/////////////////////////////////
	ft_printf("----------------NO SPECIFIERS---------------\n");
	output_OG = printf("OG -> Test String \t TEeeEEEeEEsT String\n");
	output_FT = ft_printf("FT -> Test String \t TEeeEEEeEEsT String\n");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> T \t t \n");
	output_FT = ft_printf("FT -> T \t t \n");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%c			   //
/////////////////////////////////
	ft_printf("------------%%c------------\n");
	char	ltr = 'C';
	output_OG = printf("OG -> I love %c\n", ltr);
	output_FT = ft_printf("FT -> I love %c\n", ltr);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	ltr = '\0';
	output_OG = printf("OG -> %c\n", ltr);
	output_FT = ft_printf("FT -> %c\n", ltr);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %c\n", '0' + 256);
	output_FT = ft_printf("FT -> %c\n", '0' + 256);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %c %c %c \n", '1', '2', '3');
	output_FT = ft_printf("FT -> %c %c %c \n", '1', '2', '3');
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %c %c %c \n", '2', '1', 0);
	output_FT = ft_printf("FT -> %c %c %c \n", '2', '1', 0);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %c %c %c \n", ' ', ' ', ' ');
	output_FT = ft_printf("FT -> %c %c %c \n", ' ', ' ', ' ');
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %c %c %c \n", '0', 0, '1');
	output_FT = ft_printf("FT -> %c %c %c \n", '0', 0, '1');
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
/////////////////////////////////
//				%s			   //
/////////////////////////////////
	ft_printf("------------%%s------------\n");
	char	*str = "Nuno";
	output_OG = printf("OG -> Hi I'm %s\n", str);
	output_FT = ft_printf("FT -> Hi I'm %s\n", str);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	char	long_str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	output_OG = printf("OG -> %s\n", long_str);
	output_FT = ft_printf("FT -> %s\n", long_str);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	char str2[] = "Atirei o pau no gatis, per gatis num morreus.";
	output_OG = printf("OG -> %s\n", str2);
	output_FT = ft_printf("FT -> %s\n", str2);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %s\n", "");
	output_FT = ft_printf("FT -> %s\n", "");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %s\n", "-");
	output_FT = ft_printf("FT -> %s\n", "-");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %s %s\n", "-", "4");
	output_FT = ft_printf("FT -> %s %s\n", "-", "4");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %s %s%s\n", "-", "4", "2");
	output_FT = ft_printf("FT -> %s %s%s\n", "-", "4", "2");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	char	*dummy = NULL;
	output_OG = printf("OG -> This should be NULL: %s\n", dummy);
	output_FT = ft_printf("FT -> This should be NULL: %s\n", dummy);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%p			   //
/////////////////////////////////
	ft_printf("------------%%p------------\n");
	char	*ptr = "c";
	output_OG = printf("OG -> %p\n", ptr);
	output_FT = ft_printf("FT -> %p\n", ptr);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	void *dummy_ptr = NULL;
	output_OG = printf("OG -> %p\n", dummy_ptr);
	output_FT = ft_printf("FT -> %p\n", dummy_ptr);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %p\n", (void *)-2);
	output_FT = ft_printf("FT -> %p\n", (void *)-2);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %p\n", (void *)-1);
	output_FT = ft_printf("FT -> %p\n", (void *)-1);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %p\n", (void *)1);
	output_FT = ft_printf("FT -> %p\n", (void *)1);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %p\n", (void *)15);
	output_FT = ft_printf("FT -> %p\n", (void *)15);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %p\n", (void *)16);
	output_FT = ft_printf("FT -> %p\n", (void *)16);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %p\n", (void *)17);
	output_FT = ft_printf("FT -> %p\n", (void *)17);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	ft_printf("LONG_MIN && LONG_MAX------------------------\n");

	output_OG = printf("OG ->  %p %p \n", (void*)LONG_MIN, (void*)LONG_MAX);
	output_FT = ft_printf("FT ->  %p %p \n", (void*)LONG_MIN, (void*)LONG_MAX);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	ft_printf("INT_MIN && INT_MAX------------------\n");
	output_OG = printf("OG ->  %p %p \n", (void*)INT_MIN, (void*)INT_MAX);
	output_FT = ft_printf("FT ->  %p %p \n", (void*)INT_MIN, (void*)INT_MAX);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	ft_printf("ULONG_MAX && -ULONG_MAX------\n");
	output_OG = printf("OG ->  %p %p \n", (void*)ULONG_MAX, (void*)-ULONG_MAX);
	output_FT = ft_printf("FT ->  %p %p \n", (void*)ULONG_MAX, (void*)-ULONG_MAX);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	ft_printf("0 && 0--------------------\n");
	output_OG = printf("OG ->  %p %p \n", (void*)0, (void*)0);
	output_FT = ft_printf("FT ->  %p %p \n", (void*)0, (void*)0);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%d			   //
/////////////////////////////////
	ft_printf("------------%%d------------\n");
	ft_printf("POSITIVE NUMBERS----------\n");
	int		nbr_pos = 42;
	output_OG = printf("OG -> %d\n", nbr_pos);
	output_FT = ft_printf("FT -> %d\n", nbr_pos);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	ft_printf("INT_MAX-------------------\n");
	output_OG = printf("OG -> %d\n", INT_MAX);
	output_FT = ft_printf("FT -> %d\n", INT_MAX);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	ft_printf("NEGATIVE NUMBERS----------\n");
	int		nbr_neg = -42;
	output_OG = printf("OG -> %d\n", nbr_neg);
	output_FT = ft_printf("FT -> %d\n", nbr_neg);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_neg = -1000000;
	output_OG = printf("OG -> %d\n", nbr_neg);
	output_FT = ft_printf("FT -> %d\n", nbr_neg);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> very long negative number: %d\n", -50000454);
	output_FT = ft_printf("FT -> very long negative number: %d\n", -50000454);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	ft_printf("INT_MIN--------------------\n");
	output_OG = printf("OG -> %d\n", INT_MIN);
	output_FT = ft_printf("FT -> %d\n", INT_MIN);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%i			   //
/////////////////////////////////
	ft_printf("------------%%i------------\n");
	int		nbr_i = 42;
	output_OG = printf("OG -> %i\n", nbr_i);
	output_FT = ft_printf("FT -> %i\n", nbr_i);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%u			   //
/////////////////////////////////
	ft_printf("------------%%u------------\n");
	unsigned nbr_u = 42;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %u\n", 4294967295u);
	output_FT = ft_printf("FT -> %u\n", 4294967295u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -16;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -101;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = INT_MAX;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = INT_MIN;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -9;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -99;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	nbr_u = -10;
	output_OG = printf("OG -> %u\n", nbr_u);
	output_FT = ft_printf("FT -> %u\n", nbr_u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%x			   //
/////////////////////////////////
	ft_printf("------------%%x------------\n");
	unsigned nbr_x = 520;
	output_OG = printf("OG -> %x\n", nbr_x);
	output_FT = ft_printf("FT -> %x\n", nbr_x);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> 17 in hexadecimal = %x\n", 17);
	output_FT = ft_printf("FT -> 17 in hexadecimal = %x\n", 17);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> 999999 in hexadecimal = %x\n", 999999);
	output_FT = ft_printf("FT -> 999999 in hexadecimal = %x\n", 999999);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> 4294967293 in hexadecimal = %x\n", 4294967293u);
	output_FT = ft_printf("FT -> 4294967293 in hexadecimal = %x\n", 4294967293u);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");


	output_OG = printf("OG -> %d\n", -100);
	output_FT = ft_printf("FT -> %d\n", -100);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %d\n", -15);
	output_FT = ft_printf("FT -> %d\n", -15);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %x\n", 10);
	output_FT = ft_printf("FT -> %x\n", 10);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 11);
	output_FT = ft_printf("FT -> %x\n", 11);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -42);
	output_FT = ft_printf("FT -> %x\n", -42);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 42);
	output_FT = ft_printf("FT -> %x\n", 42);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 15);
	output_FT = ft_printf("FT -> %x\n", 15);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 1000);
	output_FT = ft_printf("FT -> %x\n", 1000);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %x\n", 0);
	output_FT = ft_printf("FT -> %x\n", 0);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 1);
	output_FT = ft_printf("FT -> %x\n", 1);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 9);
	output_FT = ft_printf("FT -> %x\n", 9);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %x\n", -1);
	output_FT = ft_printf("FT -> %x\n", -1);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -2);
	output_FT = ft_printf("FT -> %x\n", -2);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %x\n", -101);
	output_FT = ft_printf("FT -> %x\n", -101);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", INT_MAX);
	output_FT = ft_printf("FT -> %x\n", INT_MAX);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", INT_MIN);
	output_FT = ft_printf("FT -> %x\n", INT_MIN);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", UINT_MAX);
	output_FT = ft_printf("FT -> %x\n", UINT_MAX);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 100);
	output_FT = ft_printf("FT -> %x\n", 100);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -99);
	output_FT = ft_printf("FT -> %x\n", -99);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -16);
	output_FT = ft_printf("FT -> %x\n", -16);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -9);
	output_FT = ft_printf("FT -> %x\n", -9);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -14);
	output_FT = ft_printf("FT -> %x\n", -14);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 16);
	output_FT = ft_printf("FT -> %x\n", 16);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 99);
	output_FT = ft_printf("FT -> %x\n", 99);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 101);
	output_FT = ft_printf("FT -> %x\n", 101);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -11);
	output_FT = ft_printf("FT -> %x\n", -11);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", -10);
	output_FT = ft_printf("FT -> %x\n", -10);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %x\n", 17);
	output_FT = ft_printf("FT -> %x\n", 17);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//				%X			   //
/////////////////////////////////
	ft_printf("------------%%X------------\n");
	unsigned nbr_X = 520;
	output_OG = printf("OG -> %X\n", nbr_X);
	output_FT = ft_printf("FT -> %X\n", nbr_X);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

/////////////////////////////////
//		% PERCENTAGE TESTS	   //
/////////////////////////////////
	ft_printf("------------%%%%------------\n");
	output_OG = printf("OG -> %%\n");
	output_FT = ft_printf("FT -> %%\n");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	
	output_OG = printf("OG -> %% %%\n");
	output_FT = ft_printf("FT -> %% %%\n");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %% %% %%\n");
	output_FT = ft_printf("FT -> %% %% %%\n");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");

	output_OG = printf("OG -> %%  %%  %%\n");
	output_FT = ft_printf("FT -> %%  %%  %%\n");
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("--------------------------------MIX-------------------------------\n");
	output_OG = printf("OG -> %%%s %%%s %%%d %clbum \t 520 in hexadecimal is %x\n", "string1", "string2", 18, 'a', 520);
	output_FT = ft_printf("FT -> %%%s %%%s %%%d %clbum \t 520 in hexadecimal is %x\n", "string1", "string2", 18, 'a', 520);
	printf("OUTPUT OG = %d\n", output_OG);
	ft_printf("OUTPUT FT = %d\n", output_FT);

	ft_printf("\n");
	return (0);
}