# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achakour <achakour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 22:46:29 by achakour          #+#    #+#              #
#    Updated: 2023/12/09 14:45:45 by achakour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putchar_fd.c ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_putunbr_fd.c  \
        print_hex_down.c print_hex_up.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)

%.o :%.c
	$(CC) $(CFLAGS) -c $^ -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all