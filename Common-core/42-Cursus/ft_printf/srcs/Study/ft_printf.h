/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:52:33 by rickymercur       #+#    #+#             */
/*   Updated: 2025/03/25 21:28:32 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_handle_x(const char *specifier, size_t len, va_list args);
int	    ft_hexapointer(unsigned long int n);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_lowerhexa(unsigned int n);
char	*ft_upperhexa(unsigned int n);
size_t	ft_strlen(const char *s);

#endif