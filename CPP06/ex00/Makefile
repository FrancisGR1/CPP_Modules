NAME  = converter

CXX   = c++ -std=c++98
FLAGS = -Werror -Wextra -Wall
SRCS  = ScalarConverter.cpp main.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = ScalarConverter.hpp

#CLANG_TIDY    = clang-tidy
#CLANG_FORMAT  = clang-format
#FORMAT_STYLE  = file


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

#.PHONY: format
#format:
#	@$(CLANG_FORMAT) -i --style=$(FORMAT_STYLE) $(SRCS) $(INC)
#
#.PHONY: tidy
#tidy:
#	@$(CLANG_TIDY) $(SRCS) -- $(FLAGS)
