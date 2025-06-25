CXX         = clang++
VERSION     = -std=c++98
FLAGS       = -Wall -Wextra -Werror $(VERSION)
FILES       = PhoneBook.cpp utils.cpp main.cpp
INCLUDES    = PhoneBook.hpp
OBJS        = $(FILES:.cpp=.o)

TARGET      = phonebook

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
