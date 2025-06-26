## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/25 17:09:35 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/26 10:59:37 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = ref

CXX     = c++
VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall $(VERSION)
SRC     = main.cpp
OBJ     = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

main.o: main.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
