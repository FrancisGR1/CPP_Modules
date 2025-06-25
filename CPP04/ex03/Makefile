NAME = a.out

VERSION = -std=c++98 -g
FLAGS   = -Werror -Wextra -Wall -Wshadow -Wno-shadow $(VERSION)
SRC     = main.cpp MateriaSource.cpp Character.cpp Ice.cpp Cure.cpp AMateria.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = AMateria.hpp IMateriaSource.hpp MateriaSource.hpp ICharacter.hpp \
	  Character.hpp Ice.hpp Cure.hpp

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
