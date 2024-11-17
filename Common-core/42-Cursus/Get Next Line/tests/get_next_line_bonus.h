/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:22:58 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/17 23:19:46 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h> 
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *s);
char	*ft_free(char **str);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*read_from_fd(int fd, char *buffer);
char	*get_line(char *buffer);
char	*clean_buffer(char *buffer);
char	*get_next_line(int fd);

#endif