NAME = Fixed
GCC = c++
GCCFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = main.cpp Fixed.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
