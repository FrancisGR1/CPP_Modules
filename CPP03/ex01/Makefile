## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/26 16:32:59 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/27 12:29:30 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = a.out

CXX     = c++
VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall $(VERSION)
SRC     = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
