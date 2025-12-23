NAME  = PMergeMe

CXX   = c++ -std=c++98
FLAGS = -g -Werror -Wextra -Wall
SRCS  = main.cpp Match.cpp Player.cpp PMergeMe.cpp CmpCounter.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = Match.hpp Player.hpp PMergeMe.hpp CmpCounter.hpp

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
