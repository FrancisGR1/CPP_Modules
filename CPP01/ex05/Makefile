## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/26 10:29:40 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/26 10:29:48 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = karen

CXX     = c++
VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall $(VERSION)
SRC     = main.cpp Karen.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = Karen.hpp

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
