NAME  = btc

CXX   = c++ -std=c++98
FLAGS = #-Werror -Wextra -Wall
SRCS  = main.cpp BitcoinExchange.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = BitcoinExchange.hpp

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
