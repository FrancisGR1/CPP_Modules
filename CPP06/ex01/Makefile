NAME  = ptr_serializer

CXX   = c++
FLAGS = -Werror -Wextra -Wall -std=c++98
SRCS  = main.cpp Data.cpp Serializer.cpp
OBJS  = $(SRCS:.cpp=.o)
INC   = Data.hpp Serializer.hpp 

CLANG_TIDY    = clang-tidy
CLANG_FORMAT  = clang-format
FORMAT_STYLE  = file


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

.PHONY: format
format:
	@$(CLANG_FORMAT) -i --style=$(FORMAT_STYLE) $(SRCS) $(INC)

.PHONY: tidy
tidy:
	@$(CLANG_TIDY) $(SRCS) -- $(FLAGS)
