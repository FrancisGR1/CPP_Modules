NAME  = PmergeMe

CXX   = c++ -std=c++98
FLAGS = -g -Werror -Wextra -Wall
SRCS  = main.cpp Value.cpp ValueMetaData.cpp Time.cpp PmergeMeVector.cpp PmergeMeDeque.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = PmergeMeVector.hpp PmergeMeDeque.hpp PmergeMeValidator.hpp Value.hpp ValueMetaData.hpp Round.hpp Time.hpp

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
