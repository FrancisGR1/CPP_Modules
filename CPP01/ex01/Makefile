VERSION     = -std=c++98
FLAGS       = -Wall -Wextra -Werror $(VERSION)
FILES       = randomChump.cpp newZombie.cpp Zombie.cpp main.cpp
INCLUDES    = Zombie.hpp Utils.hpp 
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
