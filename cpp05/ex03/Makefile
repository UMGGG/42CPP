NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp\
		intern.cpp

$(NAME): $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
