NAME  = PmergeMe

CXX   = c++ -std=c++98
FLAGS = -g -Werror -Wextra -Wall
SRCS  = main.cpp Matches.cpp Player.cpp Time.cpp utils.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = Matches.hpp Player.hpp PmergeMe.hpp Time.hpp utils.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CXX) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
