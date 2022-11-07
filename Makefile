# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:38:04 by kadjane           #+#    #+#              #
#    Updated: 2022/11/07 04:23:49 by kadjane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = philosophers.c fuc_help.c ft_routine.c fun_thread.c

NAME = philosopher

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror 


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
clean : 
	@rm -f *.o
fclean : clean
	@rm -f $(NAME)
re : fclean all