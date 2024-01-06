# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 10:59:06 by ededemog          #+#    #+#              #
#    Updated: 2024/01/06 17:49:16 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
EXEC = prog
SRCS = ft_printf.c ft_putchar.c ft_putdigit.c ft_putstr.c print_format.c ft_putptr.c
BONUS	=	
MAIN	=	main.c

OBJB	=	$(BONUS:.c=.o)

OBJM	=	$(MAIN:.c=.o)

TNAME	= 	test

OBJS 	= 	$(SRCS:.c=.o)

NAME	= 	libftprintf.a

CC		= 	clang
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar rc

RM		= 	rm -f

.c.o:
			$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

test:		$(NAME) bonus
			$(CC) $(CFLAGS) -o $(TNAME) $(MAIN) -L. -lft

all:		$(NAME)

bonus:		$(OBJB)
			$(AR) $(NAME) $(OBJB)

clean:
			$(RM) $(OBJS) $(OBJM) $(OBJB)

fclean:		clean
			$(RM) $(NAME) $(TNAME)

re:			fclean all

.PHONY:		all clean fclean re test