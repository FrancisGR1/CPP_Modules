NAME  = identify

CXX   = c++
FLAGS = -Werror -Wextra -Wall -std=c++98
SRCS  = main.cpp Base.cpp 
OBJS  = $(SRCS:.cpp=.o)
INC   = Base.hpp A.hpp B.hpp C.hpp

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
