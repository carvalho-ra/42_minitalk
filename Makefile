# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 10:32:44 by rcarvalh          #+#    #+#              #
#    Updated: 2023/02/14 11:43:28 by rcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minitalk

SRC_S = server.c

SRC_C = client.c

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

INC = -Ilibft

LIBFT = -Llibft -lft

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o:
	$(CC) -c $(INC) $(CC_FLAGS) $(SRC_S) $(SRC_C)

$(NAME): $(OBJ_S) $(OBJ_C) 
	make -C ./libft
	$(CC) $(CC_FLAGS) $(LIBFT) $(OBJ_S) -o server
	$(CC) $(CC_FLAGS) $(LIBFT) $(OBJ_C) -o client

all: $(NAME)
	
clean:
	$(RM) $(OBJ_S) $(OBJ_C)

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re
