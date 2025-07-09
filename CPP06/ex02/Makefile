NAME  = identify

CXX   = c++
FLAGS = -Werror -Wextra -Wall -std=c++23
SRCS  = main.cpp Base.cpp 
OBJS  = $(SRCS:.cpp=.o)
INC   = Base.hpp A.hpp B.hpp C.hpp

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
