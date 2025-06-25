CXX      = clang++
VERSION  = -std=c++98
FLAGS    = -Wall -Wextra -Werror $(VERSION)
FILES    = megaphone.cpp
OBJS     = $(FILES:.cpp=.o)

TARGET   = megaphone

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) $(FILES) -o $(TARGET) 

%.o: %.cpp 
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
