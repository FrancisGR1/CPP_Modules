NAME = a.out

CXX     =  c++
VERSION = -std=c++23
FLAGS   = -Werror -Wextra -Wall -Wshadow -Wno-shadow $(VERSION)
SRC     = main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp 

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
