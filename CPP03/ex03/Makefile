## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/26 16:34:02 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/27 14:10:09 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = a.out

CXX     = c++
VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall -Wshadow -Wno-shadow $(VERSION)
SRC     = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

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
