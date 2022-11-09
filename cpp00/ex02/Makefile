NAME = account
GCC = c++
GCCFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = acount.cpp test.cpp

$(NAME): $(SRCS)
	$(GCC) $(SRCS) $(GCCFLAGS) -o $(NAME)

all : $(NAME)
clean:
	rm -rf $(NAME)
re:	clean all

.PHONY: all clean re
