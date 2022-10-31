# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/10/31 13:11:45 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = philosophers.c fuc_help.c ft_routine.c

NAME = philosophers

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=thread -g

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o philosophers
clean : 
	@rm -f *.o
fclean : clean
	@rm -f $(NAME)
re : fclean all