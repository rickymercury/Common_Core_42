# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 22:12:26 by rmedeiro          #+#    #+#              #
#    Updated: 2025/03/25 21:42:30 by rmedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	handle_x.c handle_d.c ft_printf.c handle_p.c handle_u.c printf_utils.c
OBJECTS =	$(SOURCES:.c=.o)
NAME 	=	libftprintf.a


all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ 

gcc:
	gcc -Wall -Werror -Wextra ft_printf.c $(NAME)

clean:
	rm -f $(OBJECTS)
	(cd libft && make clean)
	
fclean:
	rm -f $(OBJECTS) $(NAME)
	(cd libft && make fclean)

re:	fclean all

.PHONY = all clean fclean re gcc