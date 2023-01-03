# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:29:53 by del-yaag          #+#    #+#              #
#    Updated: 2023/01/03 16:44:44 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_SRC = client.c ft_atoi.c

S_SRC = server.c ft_printf.c helpers.c

C_OBJ=$(C_SRC:.c=.o)
S_OBJ=$(S_SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT = client
SERVER = server

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJ) mini_talk.h
	$(CC) $(FLAGS) $(C_OBJ) -o $@
	
$(SERVER): $(S_OBJ) mini_talk.h
	$(CC) $(FLAGS) $(S_OBJ) -o $@

clean:
	$(RM) $(C_OBJ) $(S_OBJ)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: re fclean clean all
