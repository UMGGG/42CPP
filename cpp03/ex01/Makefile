NAME = ClapTrap
GCC = c++
GCCFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
