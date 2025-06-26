## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/25 17:10:43 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/26 11:01:46 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = weapon

CXX     = c++
VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall $(VERSION)
SRC     = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
INC     = HumanA.hpp HumanB.hpp Weapon.hpp   
OBJ     = $(SRC:.cpp=.o) 

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
