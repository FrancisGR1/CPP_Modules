NAME  = RPN

CXX   = c++ -std=c++98
FLAGS = -Werror -Wextra -Wall
SRCS  = main.cpp RPN.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = RPN.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $@ $^

%.o: %.cpp $(INC)
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
