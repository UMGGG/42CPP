NAME = zombie
GCC = c++
GCCFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
