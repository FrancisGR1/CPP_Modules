## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/25 16:37:38 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/25 16:41:04 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

CXX         = c++
VERSION     = -std=c++98
FLAGS       = -Wall -Wextra -Werror $(VERSION)
FILES       = PhoneBook.cpp utils.cpp main.cpp
INCLUDES    = PhoneBook.hpp
OBJS        = $(FILES:.cpp=.o)

NAME      = phonebook

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CXX) $(FLAGS) $(FILES) -o $(NAME) 

%.o: %.cpp 
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
