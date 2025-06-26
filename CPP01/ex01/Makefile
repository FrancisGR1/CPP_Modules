## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/25 17:04:25 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/26 10:48:40 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

CXX         = c++
VERSION     = -std=c++98
FLAGS       = -Wall -Wextra -Werror $(VERSION)
FILES       = zombieHorde.cpp Zombie.cpp main.cpp
INCLUDES    = Zombie.hpp
OBJ        = $(FILES:.cpp=.o)

NAME      = brainz

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CXX) $(FLAGS) $(FILES) -o $(NAME) 

%.o: %.cpp 
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
