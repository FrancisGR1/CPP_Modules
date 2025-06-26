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
