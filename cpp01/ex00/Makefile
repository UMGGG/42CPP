NAME = zombie
GCC = clang++
GCCFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
