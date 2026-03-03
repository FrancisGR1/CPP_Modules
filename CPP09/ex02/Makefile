NAME  = PmergeMe

CXX   = c++ -std=c++98
FLAGS = -g -Werror -Wextra -Wall
SRCS  = main.cpp PmergeMeVector.cpp Value.cpp ValueMetaData.cpp Round.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = PmergeMeVector.hpp Value.hpp ValueMetaData.hpp Round.hpp

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
