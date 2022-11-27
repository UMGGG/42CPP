NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp

$(NAME): $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
