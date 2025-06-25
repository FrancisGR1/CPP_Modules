CXX         = clang++
VERSION     = -std=c++98
FLAGS       = -Wall -Wextra -Werror $(VERSION)
FILES       = Account.cpp tests.cpp
INCLUDES    = Account.hpp
OBJS        = $(FILES:.cpp=.o)

TARGET      = test

all: $(TARGET)

$(TARGET): $(OBJS) $(INCLUDES)
	$(CXX) $(FLAGS) $(FILES) -o $(TARGET) 

%.o: %.cpp 
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
