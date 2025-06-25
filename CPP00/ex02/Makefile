## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/25 16:40:07 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/25 16:41:18 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

CXX         = c++
VERSION     = -std=c++98
FLAGS       = -Wall -Wextra -Werror $(VERSION)
FILES       = Account.cpp tests.cpp
INCLUDES    = Account.hpp
OBJS        = $(FILES:.cpp=.o)

NAME        = test

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
