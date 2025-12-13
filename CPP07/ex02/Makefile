NAME  = a.out

CXX   = c++ -std=c++98
FLAGS = -Werror -Wextra -Wall -c
SRCS  = main.cpp 
OBJS  = $(SRCS:.cpp=.o)
INC   = Array.hpp

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

.PHONY: show_instantiated_templates
show_instantiated_templates: 
	nm main.o | c++filt | grep Array
