# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 18:50:25 by khaimer           #+#    #+#              #
#    Updated: 2023/01/04 18:50:25 by khaimer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

server = server
client = client
server_bonus = server_bonus
client_bonus = client_bonus

CFLAG = gcc -Wall -Wextra -Werror
OBJ = client.c
OBJ1 = server.c
OBJ_bonus = client_bonus.c
OBJ1_bonus = server_bonus.c

all: $(server) $(client)
$(client) : $(OBJ)
			$(CFLAG) $(OBJ) -o $(client)
$(server) : $(OBJ1)
			$(CFLAG) $(OBJ1) -o $(server)
re: fclean all
clean:
		rm -rf $(server) $(client) $(server_bonus) $(client_bonus)
fclean : clean
bonus : $(server_bonus) $(client_bonus)
$(client_bonus) : $(OBJ_bonus)
					$(CFLAG) $(OBJ_bonus) -o $(client_bonus)
$(server_bonus) : $(OBJ1_bonus)
					$(CFLAG) $(OBJ1_bonus) -o $(server_bonus) 