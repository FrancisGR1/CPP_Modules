NAME = brain

VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall $(VERSION)
SRC     = main.cpp
OBJ     = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

main.o: main.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
