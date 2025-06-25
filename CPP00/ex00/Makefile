## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: frmiguel <frmiguel>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2025/06/25 16:37:20 by frmiguel          #+#    #+#             ##
##   Updated: 2025/06/25 16:42:32 by frmiguel         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

CXX      = c++
VERSION  = -std=c++98
FLAGS    = -Wall -Wextra -Werror $(VERSION)
FILES    = megaphone.cpp
OBJS     = $(FILES:.cpp=.o)

NAME   = megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(FILES) -o $(NAME) 

%.o: %.cpp 
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
