# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:29:53 by del-yaag          #+#    #+#              #
#    Updated: 2023/01/03 22:41:39 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_SRC = client.c ft_atoi.c

S_SRC = server.c ft_printf.c helpers.c

C_SRC_B = bonus/client_bonus.c bonus/ft_atoi.c bonus/ft_printf.c bonus/helpers.c

S_SRC_B = bonus/server_bonus.c bonus/ft_printf.c bonus/helpers.c

C_OBJ=$(C_SRC:.c=.o)
S_OBJ=$(S_SRC:.c=.o)

C_OBJB=$(C_SRC_B:.c=.o)
S_OBJB=$(S_SRC_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT = client
SERVER = server

CLIENT_B = client_bonus
SERVER_B = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJ) mini_talk.h
	$(CC) $(CFLAGS) $(C_OBJ) -o $@
	
$(SERVER): $(S_OBJ) mini_talk.h
	$(CC) $(CFLAGS) $(S_OBJ) -o $@
	
bonus: $(CLIENT_B) $(SERVER_B)

$(CLIENT_B): $(C_OBJB) bonus/mini_talk_bonus.h
	$(CC) $(CFLAGS) $(C_OBJB) -o $@
	
$(SERVER_B): $(S_OBJB) bonus/mini_talk_bonus.h
	$(CC) $(CFLAGS) $(S_OBJB) -o $@

clean:
	$(RM) $(C_OBJ) $(S_OBJ)
	$(RM) $(C_OBJB) $(S_OBJB)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(RM) $(CLIENT_B) $(SERVER_B)

re: fclean all

.PHONY: re fclean clean all
