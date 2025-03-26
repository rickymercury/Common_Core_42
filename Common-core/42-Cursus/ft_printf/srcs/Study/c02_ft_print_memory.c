/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c02_ft_print_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:03:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/11 22:41:20 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert_to_hex(int value)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[value / 16]);
	ft_putchar(base[value % 16]);
}

void	print_address(void *addr)
{
	char	buffer[16];
	char	*base;
	long	address;
	int		counter;

	base = "0123456789abcdef";
	address = (long)addr;
	counter = 15;
	while (counter >= 0)
	{
		buffer[counter] = base[address % 16];
		address /= 16;
		counter--;
	}
	counter = 0;
	while (counter < 16)
		ft_putchar(buffer[counter++]);

	write(1, ": ", 2);
}

void	print_ascii(void *addr, unsigned int len)
{
	unsigned int	i;
	int				char_value;
	char			*str;
	int				byte_counter;

	str = (char *)addr;
	i = 0;
	byte_counter = 0;
	while (str[i] && i < len && byte_counter < 16)
	{
		char_value = str[i];
		convert_to_hex(char_value);
		i++;
		byte_counter++;
		if (byte_counter % 2 == 0)
			ft_putchar(' ');
	}
	while (byte_counter < 16)
	{
		write(1, "  ", 2);
		byte_counter++;
		if (byte_counter % 2 == 0)
			ft_putchar(' ');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;
	int				byte_counter;

	str = (unsigned char *)addr;
	i = 0;
	while (str[i] && i < size && (int )size > 0)
	{
		print_address(addr);
		print_ascii(addr, size);
		byte_counter = 0;
		while (str[i] && i < size && byte_counter < 16)
		{
			if (str[i] >= 32 && str[i] <= 126)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
			i++;
			byte_counter++;
		}
		addr += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

int	main(void)
{
	char test_str[] = "Bonjour les amis\nC'est fou tout ce qu'on peut faire avec.\nprint_memory...\n..lol.lol..\n";
	ft_print_memory(test_str, sizeof(test_str));
	return (0);
}
