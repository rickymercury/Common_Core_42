/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:18:33 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/26 08:54:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_lowerhexa(unsigned int n)
{
	char			*str;
	int				x;
	unsigned int	num;

	num = n;
	x = ft_hexa_len(num);
	str = malloc((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[x] = '\0';
	while (x > 0)
	{
		if (num % 16 > 9)
			str[x - 1] = (num % 16) + 'a' - 10;
		else
			str[x - 1] = (num % 16) + '0';
		num /= 16;
		x--;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}

char	*ft_upperhexa(unsigned int n)
{
	char			*str;
	int				x;
	unsigned int	num;

	num = n;
	x = ft_hexa_len(num);
	str = malloc((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[x] = '\0';
	while (x > 0)
	{
		if (num % 16 > 9)
			str[x - 1] = (num % 16) + 'A' - 10;
		else
			str[x - 1] = (num % 16) + '0';
		num /= 16;
		x--;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}






/* char	*ft_lowerhexa(unsigned int n)
{
	char			*str;
	int				   x;
	unsigned int	 num;

	num = n;
	x = (ft_hexa_len(n));
	str = malloc((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, x + 1);
	str[x--] = '\0';
	while (num >= 16)
	{
		if ((num % 16) > 9)
			str[x] = (num % 16) + 87;
		else
			str[x] = (num % 16) + 48;
		num /= 16;
		x--;
	}
	if (num > 9)
		str[x] = (num % 16) + 87;
	else
		str[x] = (num % 16) + 48;
	return (str);
}

char	*ft_upperhexa(unsigned int n)
{
	char			*str;
	int				   x;
	unsigned int	 num;

	num = n;
	x = (ft_hexa_len(n));
	str = malloc((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, x + 1);
	str[x--] = '\0';
	while (num >= 16)
	{
		if ((num % 16) > 9)
			str[x] = (num % 16) + 55;
		else
			str[x] = (num % 16) + 48;
		num /= 16;
		x--;
	}
	if (num > 9)
		str[x] = (num % 16) + 55;
	else
		str[x] = (num % 16) + '0';
	return (str);
} */