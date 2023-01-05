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

NAME = Server
SNAME = Client
CFLAG = gcc -Wall -Wextra -Werror
OBJ = client.c
OBJ1 = server.c
all: $(NAME) $(SNAME)
$(SNAME) : $(OBJ)
			$(CFLAG) $(OBJ) -o $(SNAME)
$(NAME) : $(OBJ1)
			$(CFLAG) $(OBJ1) -o $(NAME)
re: fclean all
clean:
		rm -rf $(NAME) $(SNAME)
fclean : clean