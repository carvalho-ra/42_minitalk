# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 10:32:44 by rcarvalh          #+#    #+#              #
#    Updated: 2023/02/13 16:09:54 by rcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minitalk

SRC_S = server.c

SRC_C = client.c

H_SRCS = minitalk.h\
		 libft.h\

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o:
	$(CC) -c $(CC_FLAGS) $(SRC_S) $(SRC_C)

$(NAME): $(OBJ_S) $(OBJ_C)
	$(CC) $(CC_FLAGS) $(OBJ_S) -o server
	$(CC) $(CC_FLAGS) $(OBJ_C) -o client

all: $(NAME)
	
clean:
	$(RM) $(OBJ_S) $(OBJ_C)

fclean: clean

re:

.PHONY: all clean fclean re
